#include "pch.h"
#include "AdaptiveActionRendererRegistration.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace ABI::AdaptiveCards::XamlCardRenderer;
using namespace ABI::Windows::UI;

namespace AdaptiveCards { namespace XamlCardRenderer
{
    AdaptiveActionRendererRegistration::AdaptiveActionRendererRegistration()
    {
    }

    HRESULT AdaptiveActionRendererRegistration::RuntimeClassInitialize() noexcept try
    {
        m_registrationTable = std::make_shared<std::unordered_map<
            std::string,
            ComPtr<IAdaptiveActionRenderer>,
            CaseInsensitiveHash,
            CaseInsensitiveEqualTo>>();
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveActionRendererRegistration::RegisterRenderer(IAdaptiveActionRenderer* renderer)
    {
        ComPtr<IAdaptiveActionRenderer> localRenderer(renderer);
        HSTRING type;
        RETURN_IF_FAILED(localRenderer->get_Type(&type));
        std::string typeAsKey;
        RETURN_IF_FAILED(HStringToUTF8(type, typeAsKey));
        auto map = (*m_registrationTable)[typeAsKey] = localRenderer;

        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveActionRendererRegistration::GetRenderer(HSTRING type, IAdaptiveActionRenderer** result)
    {
        std::string keyAsString;
        RETURN_IF_FAILED(HStringToUTF8(type, keyAsString));
        std::unordered_map<std::string, ComPtr<IAdaptiveActionRenderer>>::iterator found = m_registrationTable->find(keyAsString);
        if (found != m_registrationTable->end())
        {
            *result = found->second.Get();
            return S_OK;
        }
        else
        {
            return E_INVALIDARG;
        }
    }

}}
