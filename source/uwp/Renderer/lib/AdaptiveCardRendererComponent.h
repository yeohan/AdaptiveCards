﻿#pragma once

#include "AdaptiveCards.Rendering.Uwp.h"

namespace AdaptiveCards { namespace Rendering { namespace Uwp
{

    // This class is effectively a singleton, and stays around between subsequent renders.
    class AdaptiveCardRenderer :
        public Microsoft::WRL::RuntimeClass<
            Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::RuntimeClassType::WinRtClassicComMix>,
            Microsoft::WRL::Implements<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardRenderer>,
            Microsoft::WRL::FtmBase>
    {
        InspectableClass(RuntimeClass_AdaptiveCards_Rendering_Uwp_AdaptiveCardRenderer, BaseTrust)

    public:
        HRESULT RuntimeClassInitialize();

        // IAdaptiveCardRenderer
        IFACEMETHODIMP put_OverrideStyles(_In_ ABI::Windows::UI::Xaml::IResourceDictionary* overrideDictionary);
        IFACEMETHODIMP get_OverrideStyles(_COM_Outptr_ ABI::Windows::UI::Xaml::IResourceDictionary** overrideDictionary);
        IFACEMETHODIMP put_HostConfig(_In_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveHostConfig* hostConfig);
        IFACEMETHODIMP get_HostConfig(_In_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveHostConfig** hostConfig);
        IFACEMETHODIMP SetFixedDimensions(_In_ UINT32 desiredWidth, _In_ UINT32 desiredHeight);
        IFACEMETHODIMP ResetFixedDimensions();

        IFACEMETHODIMP RenderAdaptiveCard(_In_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCard* adaptiveCard,
            _COM_Outptr_ ABI::AdaptiveCards::Rendering::Uwp::IRenderedAdaptiveCard** result);
        HRESULT RenderCardAsXamlAsync(_In_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCard* adaptiveCard,
            _COM_Outptr_ ABI::Windows::Foundation::IAsyncOperation<ABI::AdaptiveCards::Rendering::Uwp::RenderedAdaptiveCard*>** result);

        IFACEMETHODIMP RenderAdaptiveCardFromJsonString(_In_ HSTRING adaptiveJson,
            _COM_Outptr_ ABI::AdaptiveCards::Rendering::Uwp::IRenderedAdaptiveCard** result);
        HRESULT RenderAdaptiveJsonAsXamlAsync(_In_ HSTRING adaptiveJson,
            _COM_Outptr_ ABI::Windows::Foundation::IAsyncOperation<ABI::AdaptiveCards::Rendering::Uwp::RenderedAdaptiveCard*>** result);

        IFACEMETHODIMP RenderAdaptiveCardFromJson(_In_ ABI::Windows::Data::Json::IJsonObject* adaptiveJson,
            _COM_Outptr_ ABI::AdaptiveCards::Rendering::Uwp::IRenderedAdaptiveCard** result);

        IFACEMETHODIMP get_ElementRenderers(_COM_Outptr_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveElementRendererRegistration** result);

        ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveHostConfig* GetHostConfig();
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> GetMergedDictionary();
        bool GetFixedDimensions(_Out_ UINT32* width, _Out_ UINT32* height);

        IFACEMETHODIMP get_ResourceResolvers(
            _COM_Outptr_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardResourceResolvers** value);

    private:
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> m_overrideDictionary;
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> m_defaultResourceDictionary;
        Microsoft::WRL::ComPtr<ABI::Windows::UI::Xaml::IResourceDictionary> m_mergedResourceDictionary;
        Microsoft::WRL::ComPtr<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveHostConfig> m_hostConfig;
        Microsoft::WRL::ComPtr<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardResourceResolvers> m_resourceResolvers;
        Microsoft::WRL::ComPtr<ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveElementRendererRegistration> m_elementRendererRegistration;

        bool m_explicitDimensions = false;
        UINT32 m_desiredWidth = 0;
        UINT32 m_desiredHeight = 0;

        HRESULT CreateAdaptiveCardFromJsonString(_In_ HSTRING adaptiveJson, _COM_Outptr_ ABI::AdaptiveCards::Rendering::Uwp::IAdaptiveCardParseResult** adaptiveCard);
        HRESULT RegisterDefaultElementRenderers();
        void InitializeDefaultResourceDictionary();
        HRESULT SetMergedDictionary();
    };

    ActivatableClass(AdaptiveCardRenderer);
}}}