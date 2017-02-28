//
//  DjinniTextBlockImpl.hpp
//  AdaptiveCards.Objc
//
//  Created by Ricardo Arenas on 2/28/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

#ifndef DjinniTextBlockImpl_hpp
#define DjinniTextBlockImpl_hpp

#include <stdio.h>
#include <memory>
#include "DjinniTextBlock.hpp"
#include "DjinniBaseCardElement.hpp"
#include "TextBlock.h"
#include "enums.h"
#include "DjinniTextColor.hpp"

namespace AdaptiveCards
{
    class TextBlockImpl : public TextBlock, public djinni::DjinniTextBlock, public djinni::DjinniBaseCardElement
    {
    public:
        
        TextBlockImpl()
        {
            m_textBlock = std::make_shared<TextBlock>();
        }
        
        void SetText(const std::string & text)
        {
            m_textBlock->SetText(text);
        };
        
        std::string GetText()
        {
            return m_textBlock->GetText();
        }
        
        void SetWrap(bool wrap)
        {
            m_textBlock->SetWrap(wrap);
        }
        
        bool GetWrap()
        {
            return m_textBlock->GetWrap();
        }
        
        void SetTextColor(djinni::DjinniTextColor textColor)
        {
        }
        
        djinni::DjinniTextColor GetTextColor()
        {
            return djinni::DjinniTextColor::DEFAULT;
        }
        
        
        
        
    private:
        std::shared_ptr<TextBlock> m_textBlock;
    };
}


#endif /* DjinniTextBlockImpl_hpp */
