//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#ifndef AdaptiveCardBridge_h
#define AdaptiveCardBridge_h

#ifdef __cplusplus
extern "C" {
#endif
    
    const void* AdaptiveCard_Init();
    const void* AdaptiveCard_Init2(const char* version, const char* minVersion, const char* fallbacktText, const char* backgroundImage);
    
    const char* AdaptiveCard_GetVersion(const void* obj);
    void AdaptiveCard_SetVersion(const void* obj, const char* version);
    
    const char* AdaptiveCard_GetMinVersion(const void* obj);
    void AdaptiveCard_SetMinVersion(const void* obj, const char* minVersion);
    
    const char* AdaptiveCard_GetFallbackText(const void* obj);
    void AdaptiveCard_SetFallbackText(const void* obj, const char* fallbackText);
    
    int AdaptiveCard_GetElementType(const void* obj);
    
    const void* AdaptiveCard_DeserializeFromString(const char* jsonString);
    
#ifdef __cplusplus
}
#endif


#endif /* AdaptiveCardBridge_h */
