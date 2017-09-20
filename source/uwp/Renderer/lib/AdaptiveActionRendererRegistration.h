#pragma once

#include "AdaptiveCards.XamlCardRenderer.h"
#include "Util.h"

namespace AdaptiveCards {
    namespace XamlCardRenderer
    {
        class AdaptiveActionRendererRegistration :
            public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            Microsoft::WRL::Implements<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveActionRendererRegistration>,
            Microsoft::WRL::FtmBase>
        {
            InspectableClass(RuntimeClass_AdaptiveCards_XamlCardRenderer_AdaptiveActionRendererRegistration, BaseTrust)

        public:
            AdaptiveActionRendererRegistration();
            HRESULT RuntimeClassInitialize() noexcept;

            IFACEMETHODIMP RegisterRenderer(_In_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveActionRenderer* renderer);
            IFACEMETHODIMP GetRenderer(_In_ HSTRING type, _COM_Outptr_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveActionRenderer** result);

        private:
            std::shared_ptr<std::unordered_map<
                std::string,
                Microsoft::WRL::ComPtr<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveActionRenderer>,
                CaseInsensitiveHash,
                CaseInsensitiveEqualTo>> m_registrationTable;
        };

        ActivatableClass(AdaptiveActionRendererRegistration);
    }
}
