//
//  TextBlockImpl.hpp
//  
//
//  Created by Ricardo Arenas on 3/2/17.
//
//

#ifndef TextBlockImpl_hpp
#define TextBlockImpl_hpp

#include <stdio.h>
#include <json.h>
#include <memory>
#include <string>
#include "DjinniTextBlock.hpp"
#include "DjinniBaseCardElement.hpp"
#include "DjinniTextColor.hpp"
#include "TextBlock.h"

namespace AdaptiveCards
{
    class TextBlockImpl : public DjinniTextBlock, public DjinniBaseCardElement
    {
    public:
        TextBlockImpl();
        
        void SetText(const std::string& text);
        
        std::string GetText();
        
        void SetWrap(bool wrap);
        
        bool GetWrap();
        
        void SetTextColor(DjinniTextColor textColor);
        
        DjinniTextColor GetTextColor();
        
        std::shared_ptr<DjinniBaseCardElement> AsBaseCardElement();
        
        std::string GetSpeak();
        
        void SetSpeak(const std::string& speak);
        
        std::shared_ptr<TextBlock> m_textBlock;
    };
}

#endif /* TextBlockImpl_hpp */
