//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#include "BaseCardElementBridge.h"
#include "BaseCardElement.h"

#ifdef __cplusplus
extern "C" {
#endif
    
    int BaseCardElement_GetSeperationStyle(const void* object)
    {
        AdaptiveCards::BaseCardElement *element = (AdaptiveCards::BaseCardElement *) object;
        return static_cast<int>(element->GetSeparationStyle());
    }
    
    void BaseCardElement_SetSeperationStyle(const void* object, int seperationStyle)
    {
        AdaptiveCards::BaseCardElement *element = (AdaptiveCards::BaseCardElement *) object;
        element->SetSeparationStyle(static_cast<AdaptiveCards::SeparationStyle>(seperationStyle));
    }
    
    const char* BaseCardElement_GetSpeak(const void* object)
    {
        AdaptiveCards::BaseCardElement *element = (AdaptiveCards::BaseCardElement *) object;
        return element->GetSpeak().c_str();
    }
    
    void BaseCardElement_SetSpeak(const void* object, const char* speak)
    {
        AdaptiveCards::BaseCardElement *element = (AdaptiveCards::BaseCardElement *) object;
        element->SetSpeak(std::string(speak));
    }
    
    int BaseCardElement_GetElementType(const void* object)
    {
        AdaptiveCards::BaseCardElement *element = (AdaptiveCards::BaseCardElement *) object;
        return static_cast<int>(element->GetSeparationStyle());
    }
    
#ifdef __cplusplus
}
#endif
