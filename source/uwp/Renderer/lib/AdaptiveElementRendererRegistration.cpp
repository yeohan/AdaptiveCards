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
        m_registrationTable = std::make_shared<std::unordered_map<std::string, ComPtr<IAdaptiveElementRenderer>>>();
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveRendererRegistration::RegisterRenderer(HSTRING type, IAdaptiveElementRenderer* renderer)
    {
        std::string keyAsString;
        RETURN_IF_FAILED(HStringToUTF8(type, keyAsString));
        ComPtr<IAdaptiveElementRenderer> localRenderer(renderer);
        auto map = (*m_registrationTable)[keyAsString] = localRenderer;

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
