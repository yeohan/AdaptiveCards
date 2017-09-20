#include "pch.h"
#include "AdaptiveElementRendererRegistration.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace ABI::AdaptiveCards::XamlCardRenderer;
using namespace ABI::Windows::UI;

namespace AdaptiveCards { namespace XamlCardRenderer
{
    AdaptiveRendererRegistration::AdaptiveRendererRegistration()
    {

    }

    HRESULT AdaptiveRendererRegistration::RuntimeClassInitialize() noexcept try
    {
        m_registrationTable = std::make_shared<std::unordered_map<
            std::string,
            ComPtr<IAdaptiveElementRenderer>,
            CaseInsensitiveHash,
            CaseInsensitiveEqualTo>>();
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveRendererRegistration::RegisterRenderer(IAdaptiveElementRenderer* renderer)
    {
        ComPtr<IAdaptiveElementRenderer> localRenderer(renderer);
        HSTRING type;
        RETURN_IF_FAILED(localRenderer->get_Type(&type));
        std::string typeAsKey;
        RETURN_IF_FAILED(HStringToUTF8(type, typeAsKey));
        auto map = (*m_registrationTable)[typeAsKey] = localRenderer;

        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRendererRegistration::GetRenderer(HSTRING type, IAdaptiveElementRenderer** result)
    {
        std::string keyAsString;
        RETURN_IF_FAILED(HStringToUTF8(type, keyAsString));
        std::unordered_map<std::string, ComPtr<IAdaptiveElementRenderer>>::iterator found = m_registrationTable->find(keyAsString);
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
