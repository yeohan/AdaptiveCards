#include "pch.h"
#include "XamlCardRendererComponent.h"

#include <windows.foundation.collections.h>
#include <Windows.UI.Xaml.h>

#include "AdaptiveCard.h"
#include "AdaptiveChoiceInputRenderer.h"
#include "AdaptiveChoiceSetInputRenderer.h"
#include "AdaptiveColumnRenderer.h"
#include "AdaptiveColumnSetRenderer.h"
#include "AdaptiveContainerRenderer.h"
#include "AdaptiveDateInputRenderer.h"
#include "AdaptiveElementRendererRegistration.h"
#include "AdaptiveFactRenderer.h"
#include "AdaptiveFactSetRenderer.h"
#include "AdaptiveHostConfig.h"
#include "AdaptiveImageRenderer.h"
#include "AdaptiveImageSetRenderer.h"
#include "AdaptiveNumberInputRenderer.h"
#include "AdaptiveTextBlockRenderer.h"
#include "AdaptiveTextInputRenderer.h"
#include "AdaptiveTimeInputRenderer.h"
#include "AdaptiveToggleInputRenderer.h"
#include "AdaptiveRenderContext.h"
#include "AsyncOperations.h"
#include "XamlBuilder.h"
#include "XamlHelpers.h"


using namespace concurrency;
using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::XamlCardRenderer;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::Storage::Streams;
using namespace ABI::Windows::UI;
using namespace ABI::Windows::UI::Core;
using namespace ABI::Windows::UI::Xaml;
using namespace ABI::Windows::UI::Xaml::Controls;
using namespace ABI::Windows::UI::Xaml::Media;
using namespace ABI::Windows::UI::Xaml::Media::Imaging;

namespace AdaptiveCards { namespace XamlCardRenderer
{
    XamlCardRenderer::XamlCardRenderer()
    {
    }

    HRESULT XamlCardRenderer::RuntimeClassInitialize()
    {
        m_events.reset(new ActionEventSource);
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveElementRendererRegistration>(&m_elementRendererRegistration));
        RETURN_IF_FAILED(RegisterDefaultElementRenderers(m_elementRendererRegistration.Get()));
        RETURN_IF_FAILED(RegisterDefaultActionRenderers(m_actionRendererRegistration.Get()));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveHostConfig>(&m_hostConfig));
        return MakeAndInitialize<AdaptiveRenderContext>(&m_renderContext,
            m_hostConfig.Get(),
            m_elementRendererRegistration.Get(),
            m_actionRendererRegistration.Get());
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::SetRenderOptions(ABI::AdaptiveCards::XamlCardRenderer::RenderOptions /*options*/)
    {
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::SetOverrideStyles(ABI::Windows::UI::Xaml::IResourceDictionary* overrideDictionary)
    {
        m_overrideDictionary = overrideDictionary;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT  XamlCardRenderer::SetHostConfig(IAdaptiveHostConfig* hostConfig)
    {
        m_hostConfig = hostConfig;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::add_Action(
        ABI::Windows::Foundation::ITypedEventHandler<ABI::AdaptiveCards::XamlCardRenderer::XamlCardRenderer*, ABI::AdaptiveCards::XamlCardRenderer::AdaptiveActionEventArgs*>* handler,
        EventRegistrationToken* token)
    {
        return m_events->Add(handler, token);
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::remove_Action(EventRegistrationToken token)
    {
        return m_events->Remove(token);
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::RenderCardAsXaml(
        IAdaptiveCard* adaptiveCard, 
        IUIElement** result) try
    {
        *result = nullptr;

        if (adaptiveCard)
        {
            XamlBuilder builder;
            ComPtr<IUIElement> xamlTreeRoot;
            
            if (m_overrideDictionary != nullptr)
            {
                builder.SetOverrideDictionary(m_overrideDictionary.Get());
            }

            if (m_hostConfig != nullptr)
            {
                builder.SetHostConfig(m_hostConfig.Get());
            }

            // This path is used for synchronous Xaml card rendering, so we don't want
            // to manually download the image assets and instead just want xaml to do
            // that automatically
            builder.SetEnableXamlImageHandling(true);

            builder.BuildXamlTreeFromAdaptiveCard(adaptiveCard, &xamlTreeRoot, this);
            *result = xamlTreeRoot.Detach();
        }

        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::RenderCardAsXamlAsync(
        IAdaptiveCard* adaptiveCard,
        IAsyncOperation<UIElement*>** result)
    {
        *result = Make<RenderCardAsXamlAsyncOperation>(adaptiveCard, this).Detach();
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::RenderAdaptiveJsonAsXaml(
        HSTRING adaptiveJson,
        IUIElement** result)
    {
        ComPtr<IAdaptiveCard> adaptiveCard;
        RETURN_IF_FAILED(CreateAdaptiveCardFromJson(adaptiveJson, &adaptiveCard));

        return RenderCardAsXaml(adaptiveCard.Get(), result);
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::RenderAdaptiveJsonAsXamlAsync(
        HSTRING adaptiveJson,
        IAsyncOperation<UIElement*>** result)
    {
        ComPtr<IAdaptiveCard> adaptiveCard;
        RETURN_IF_FAILED(CreateAdaptiveCardFromJson(adaptiveJson, &adaptiveCard));

        return RenderCardAsXamlAsync(adaptiveCard.Get(), result);
    }

    IFACEMETHODIMP XamlCardRenderer::get_ElementRendererRegistration(ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRendererRegistration** result)
    {
        *result = m_elementRendererRegistration.Get();
        return S_OK;
    }

    IFACEMETHODIMP XamlCardRenderer::get_ActionRendererRegistration(ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveActionRendererRegistration** result)
    {
        *result = m_actionRendererRegistration.Get();
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::CreateAdaptiveCardFromJson(HSTRING adaptiveJson, ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveCard** adaptiveCard)
    {
        ComPtr<IAdaptiveCardStatics> adaptiveCardStatics;
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveCardStaticsImpl>(&adaptiveCardStatics));
        RETURN_IF_FAILED(adaptiveCardStatics->CreateCardFromJson(adaptiveJson, adaptiveCard));
        return S_OK;
    }

    HRESULT XamlCardRenderer::SendActionEvent(IAdaptiveActionEventArgs* eventArgs)
    {
        return m_events->InvokeAll(this, eventArgs);
    }

    IAdaptiveHostConfig* XamlCardRenderer::GetHostConfig()
    {
        return m_hostConfig.Get();
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::RegisterDefaultElementRenderers(
        IAdaptiveElementRendererRegistration* registration)
    {
        ComPtr<IAdaptiveElementRendererRegistration> localRegistration(registration);
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveChoiceInputRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveChoiceSetInputRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveColumnRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveColumnSetRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveContainerRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveDateInputRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveFactRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveFactSetRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveImageRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveImageSetRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveNumberInputRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveTextBlockRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveTextInputRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveTimeInputRenderer>().Get()));
        RETURN_IF_FAILED(m_elementRendererRegistration->RegisterRenderer(Make<AdaptiveToggleInputRenderer>().Get()));
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT XamlCardRenderer::RegisterDefaultActionRenderers(
        IAdaptiveActionRendererRegistration* registration)
    {
        ComPtr<IAdaptiveActionRendererRegistration> localRegistration(registration);
        return S_OK;
    }

}}