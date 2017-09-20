#pragma once

#include "AdaptiveCards.XamlCardRenderer.h"
#include "Util.h"

namespace AdaptiveCards { namespace XamlCardRenderer
{
    class AdaptiveElementRendererRegistration :
        public Microsoft::WRL::RuntimeClass<
        Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
        Microsoft::WRL::Implements<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRendererRegistration>,
        Microsoft::WRL::FtmBase>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_XamlCardRenderer_AdaptiveElementRendererRegistration, BaseTrust)

    public:
        AdaptiveElementRendererRegistration();
        HRESULT RuntimeClassInitialize() noexcept;

        IFACEMETHODIMP RegisterRenderer(_In_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer* renderer);
        IFACEMETHODIMP GetRenderer(_In_ HSTRING type, _COM_Outptr_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer** result);

    private:
        std::shared_ptr<
            std::unordered_map<std::string, 
            Microsoft::WRL::ComPtr<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer>,
            CaseInsensitiveHash,
            CaseInsensitiveEqualTo>> m_registrationTable;

    };

    ActivatableClass(AdaptiveElementRendererRegistration);
}}
