#pragma once

#include "AdaptiveCards.XamlCardRenderer.h"

namespace AdaptiveCards { namespace XamlCardRenderer
{
    struct CaseInsensitiveEqualTo {
        bool operator() (const std::string& lhs, const std::string& rhs) const {
            return strncasecmp(lhs.c_str(), rhs.c_str(), CHAR_MAX) == 0;
        }
    };

    struct CaseInsensitiveHash {
        size_t operator() (const std::string& keyval) const {
            return std::accumulate(keyval.begin(), keyval.end(), size_t{ 0 }, [](size_t acc, char c) { return acc + static_cast<size_t>(std::tolower(c)); });
        }
    };

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

        IFACEMETHODIMP RegisterRenderer(_In_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer* renderer);
        IFACEMETHODIMP GetRenderer(_In_ HSTRING type, _COM_Outptr_ ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer** result);

    private:
        std::shared_ptr<
            std::unordered_map<std::string, 
            Microsoft::WRL::ComPtr<ABI::AdaptiveCards::XamlCardRenderer::IAdaptiveElementRenderer>,
            CaseInsensitiveHash,
            CaseInsensitiveEqualTo>> m_registrationTable;

    };

    ActivatableClass(AdaptiveRendererRegistration);
}}
