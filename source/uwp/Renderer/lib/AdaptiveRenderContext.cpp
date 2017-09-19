#include "pch.h"

#include "AdaptiveRenderContext.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::XamlCardRenderer;
using namespace ABI::Windows::Foundation;

namespace AdaptiveCards { namespace XamlCardRenderer
{
    HRESULT AdaptiveRenderContext::RuntimeClassInitialize() noexcept try
    {
        return S_OK;
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_HostConfig(IAdaptiveHostConfig** value)
    {
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_RendererRegistration(IAdaptiveRendererRegistration** value)
    {
        return S_OK;
    }
}}
