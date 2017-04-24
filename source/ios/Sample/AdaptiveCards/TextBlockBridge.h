//
//  TextBlockBridge.h
//  Sample
//
//  Created by Esteban Chavez on 4/14/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

#ifndef TextBlockBridge_h
#define TextBlockBridge_h

#ifdef __cplusplus
extern "C" {
#endif
    
    const void *TextBlock_Initialize();
    const void *TextBlock_InitializeWithArgs(
        int seperationStyle,
        const char *speak,
        const char *text,
        int textSize,
        int textWeight,
        int textColor,
        bool isSubtle,
        bool wrap,
        int maxLines,
        int horizontalAlignment
    );
    
    const char* TextBlock_GetText(const void* object);
    void TextBlock_SetText(const void* object, const char* text);
    
    int TextBlock_GetTextSize(const void* object);
    void TextBlock_SetTextSize(const void* object, int textSize);
    
    int TextBlock_GetTextWeight(const void* object);
    void TextBlock_SetTextWeight(const void* object, int textWeight);
    
    int TextBlock_GetTextColor(const void* object);
    void TextBlock_SetTextColor(const void* object, int textColor);
    
    bool TextBlock_GetWrap(const void* object);
    void TextBlock_SetWrap(const void* object, bool wrap);
    
    bool TextBlock_GetIsSubtle(const void* object);
    void TextBlock_SetIsSubtle(const void* object, bool isSubtle);

    int TextBlock_GetMaxLines(const void* object);
    void TextBlock_SetMaxLines(const void* object, int maxLines);
    
    int TextBlock_GetHorizontalAlignment(const void* object);
    void TextBlock_SetHorizontalAlignment(const void* object, int textWeight);
    
#ifdef __cplusplus
}
#endif



#endif /* TextBlockBridge_h */
