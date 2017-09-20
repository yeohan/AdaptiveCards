#include "pch.h"

#include "AdaptiveFactRenderer.h"
#include "enums.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::XamlCardRenderer;
using namespace ABI::Windows::Foundation;

namespace AdaptiveCards { namespace XamlCardRenderer
{
    HRESULT AdaptiveFactRenderer::RuntimeClassInitialize() noexcept try
    {
        return S_OK;
    } CATCH_RETURN;


    _Use_decl_annotations_
    HRESULT AdaptiveFactRenderer::Render(
        IAdaptiveCardElement* cardElement,
        IAdaptiveRenderContext* renderContext,
        ABI::Windows::UI::Xaml::IUIElement** result)
    {
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveFactRenderer::get_Type(HSTRING* type)
    {
        return UTF8ToHString(CardElementTypeToString(CardElementType::Fact), type);
    }
}}
