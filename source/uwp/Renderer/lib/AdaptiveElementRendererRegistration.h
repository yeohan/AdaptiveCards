#pragma once

#include "AdaptiveCards.XamlCardRenderer.h"

namespace AdaptiveCards { namespace XamlCardRenderer
{
    class AdaptiveRendererRegistration :
        public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        Microsoft::WRL::Implements<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveRendererRegistration>,
        Microsoft::WRL::FtmBase>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_XamlCardRenderer_AdaptiveRendererRegistration, BaseTrust)

    public:
        AdaptiveRendererRegistration();
        HRESULT RuntimeClassInitialize() noexcept;

        IFACEMETHODIMP RegisterRenderer(_In_ HSTRING type, _In_  ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer* renderer);
        IFACEMETHODIMP GetRenderer(_In_ HSTRING type, _COM_Outptr_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer** result);

    private:
        std::shared_ptr<std::unordered_map<std::string, Microsoft::WRL::ComPtr<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer>>> m_registrationTable;

    };

    ActivatableClass(AdaptiveRendererRegistration);
}}
