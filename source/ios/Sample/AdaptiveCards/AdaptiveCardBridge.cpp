//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#include "AdaptiveCard.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    const void* AdaptiveCard_Init()
    {
        AdaptiveCards::AdaptiveCard* card = new AdaptiveCards::AdaptiveCard();
        return (void*) card;
        
    }
    const void* AdaptiveCard_Init2(const char* version, const char* minVersion, const char* fallbacktText, const char* backgroundImage)
    {
        AdaptiveCards::AdaptiveCard* card = new AdaptiveCards::AdaptiveCard(std::string(version), std::string(minVersion), std::string(fallbacktText), std::string(backgroundImage));
        return (void*) card;
    }
    
    const char* AdaptiveCard_GetVersion(const void* obj)
    {
        AdaptiveCards::AdaptiveCard* card = (AdaptiveCards::AdaptiveCard*) obj;
        const char* retval = card->GetVersion().c_str();
        return retval;
    }
    
    void AdaptiveCard_SetVersion(const void* obj, const char* version)
    {
        AdaptiveCards::AdaptiveCard* card = (AdaptiveCards::AdaptiveCard*) obj;
        card->SetVersion(std::string(version));
    }
    
    const char* AdaptiveCard_GetMinVersion(const void* obj)
    {
        AdaptiveCards::AdaptiveCard* card = (AdaptiveCards::AdaptiveCard*) obj;
        const char* retval = card->GetMinVersion().c_str();
        return retval;
    }
    
    void AdaptiveCard_SetMinVersion(const void* obj, const char* minVersion)
    {
        AdaptiveCards::AdaptiveCard* card = (AdaptiveCards::AdaptiveCard*) obj;
        card->SetMinVersion(std::string(minVersion));
    }
    
    const char* AdaptiveCard_GetFallbackText(const void* obj)
    {
        AdaptiveCards::AdaptiveCard* card = (AdaptiveCards::AdaptiveCard*) obj;
        const char* retval = card->GetFallbackText().c_str();
        return retval;
    }
    
    void AdaptiveCard_SetFallbackText(const void* obj, const char* fallbackText)
    {
        AdaptiveCards::AdaptiveCard* card = (AdaptiveCards::AdaptiveCard*) obj;
        card->SetFallbackText(std::string(fallbackText));
    }
    
    int AdaptiveCard_GetElementType(const void* obj)
    {
        AdaptiveCards::AdaptiveCard* card = (AdaptiveCards::AdaptiveCard*) obj;
        return static_cast<int>(card->GetElementType());
    }
    
    const void* AdaptiveCard_DeserializeFromString(const char* jsonString)
    {
        std::shared_ptr<AdaptiveCards::AdaptiveCard> card = AdaptiveCards::AdaptiveCard::DeserializeFromString(std::string(jsonString));
        return (void*) card.get();
    }
    
#ifdef __cplusplus
}
#endif
