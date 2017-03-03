//
//  TextBlockImpl.cpp
//  
//
//  Created by Ricardo Arenas on 3/2/17.
//
//

#include "TextBlockImpl.hpp"

using namespace AdaptiveCards;

TextBlockImpl::TextBlockImpl()
{
    m_textBlock = std::make_shared<TextBlock>();
}

std::shared_ptr<DjinniTextBlock> DjinniTextBlock::Create()
{
    return std::make_shared<TextBlockImpl>();
}

std::shared_ptr<DjinniTextBlock> DjinniTextBlock::Deserialize(const std::string & jsonString)
{
    Json::Value jsonRoot;
    Json::Reader jsonReader;
    bool wasParsed = jsonReader.parse(jsonString, jsonRoot);
    if (wasParsed)
    {
        auto textBlock = std::make_shared<TextBlockImpl>();
        textBlock->m_textBlock = TextBlock::Deserialize(jsonRoot);
        return textBlock;
    }
    else
    {
        throw std::invalid_argument("Invalid Argument");
    }
}

void TextBlockImpl::SetText(const std::string& text)
{
    m_textBlock->SetText(text);
}

std::string TextBlockImpl::GetText()
{
    return m_textBlock->GetText();
}

void TextBlockImpl::SetWrap(bool wrap)
{
    m_textBlock->SetWrap(wrap);
}

bool TextBlockImpl::GetWrap()
{
    return m_textBlock->GetWrap();
}

void TextBlockImpl::SetTextColor(DjinniTextColor textColor)
{
}

DjinniTextColor TextBlockImpl::GetTextColor()
{
    return DjinniTextColor::DEFAULT;
}

std::shared_ptr<DjinniBaseCardElement> TextBlockImpl::AsBaseCardElement()
{
    return std::shared_ptr<DjinniBaseCardElement>((DjinniBaseCardElement*)this);
}

std::string TextBlockImpl::GetSpeak()
{
    return m_textBlock->GetSpeak();
}

void TextBlockImpl::SetSpeak(const std::string& speak)
{
    m_textBlock->SetSpeak(speak);
}
