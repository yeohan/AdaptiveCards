//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#include <stdio.h>
#include "TextBlock.h"

#ifdef __cplusplus
extern "C" {
#endif

const void* TextBlock_Initialize
(
)
{
    AdaptiveCards::TextBlock *textBlock = new AdaptiveCards::TextBlock();
    return (void *)textBlock;
}

const void* TextBlock_InitializeWithArgs
(
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
)
{
    
    AdaptiveCards::TextBlock *textBlock = new AdaptiveCards::TextBlock(
        static_cast<AdaptiveCards::SeparationStyle>(seperationStyle),
        std::string(speak),
        std::string(text),
        static_cast<AdaptiveCards::TextSize>(textSize),
        static_cast<AdaptiveCards::TextWeight>(textWeight),
        static_cast<AdaptiveCards::TextColor>(textColor),
        isSubtle,
        wrap,
        maxLines,
        static_cast<AdaptiveCards::HorizontalAlignment>(horizontalAlignment)
    );
    
    return (void *)textBlock;
}
    
const char* TextBlock_GetText(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    static char retval[2048];
    strcpy(retval, textBlock->GetText().c_str());
    return retval;
}
    
void TextBlock_SetText(const void* object, const char* text)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetText(std::string(text));
}
    
int TextBlock_GetTextSize(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    return (static_cast<int>(textBlock->GetTextSize()));
}

void TextBlock_SetTextSize(const void* object, int textSize)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetTextSize(static_cast<AdaptiveCards::TextSize>(textSize));
}
    
int TextBlock_GetTextWeight(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    return (static_cast<int>(textBlock->GetTextWeight()));
}
    
void TextBlock_SetTextWeight(const void* object, int textWeight)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetTextWeight(static_cast<AdaptiveCards::TextWeight>(textWeight));
}
    
int TextBlock_GetTextColor(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    return (static_cast<int>(textBlock->GetTextColor()));
}
    
void TextBlock_SetTextColor(const void* object, int textColor)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetTextColor(static_cast<AdaptiveCards::TextColor>(textColor));
}
    
bool TextBlock_GetWrap(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    return textBlock->GetWrap();
}
    
void TextBlock_SetWrap(const void* object, bool wrap)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetWrap(wrap);
}
    
bool TextBlock_GetIsSubtle(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    return textBlock->GetIsSubtle();
}
    
void TextBlock_SetIsSubtle(const void* object, bool isSubtle)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetIsSubtle(isSubtle);
}
    
int TextBlock_GetMaxLines(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    return textBlock->GetMaxLines();
}
    
void TextBlock_SetMaxLines(const void* object, int maxLines)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetMaxLines(maxLines);
}
    
int TextBlock_GetHorizontalAlignment(const void* object)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    return (static_cast<int>(textBlock->GetTextColor()));
}
    
void TextBlock_SetHorizontalAlignment(const void* object, int horizontalAlignment)
{
    AdaptiveCards::TextBlock *textBlock = (AdaptiveCards::TextBlock *) object;
    textBlock->SetHorizontalAlignment(static_cast<AdaptiveCards::HorizontalAlignment>(horizontalAlignment));
}

#ifdef __cplusplus
}
#endif
