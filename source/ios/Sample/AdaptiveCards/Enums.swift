//
//  Enums.swift
//  Sample
//
//  Created by Esteban Chavez on 4/18/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import Foundation

public enum CardElementType : Int32
{
    case Unsupported = 0,
    AdaptiveCard,
    TextBlock,
    Image,
    Container,
    Column,
    ColumnSet,
    FactSet,
    Fact,
    ImageGallery,
    ActionGroup
}

public enum AdaptiveCardSchemaKey : Int32
{
    case SchemaType = 0,
    Body,
    Version,
    MinVersion,
    FallbackText,
    BaseCardElement,
    Separation,
    Speak,
    Url,
    ImageStyle,
    ImageSize,
    AltText,
    HorizontalAlignment,
    Text,
    TextSize,
    TextWeight,
    TextColor,
    IsSubtle,
    Wrap,
    MaxLines,
    Items,
    Columns,
    Size,
    Facts,
    Title,
    Value
};

public enum TextSize : Int32
{
    case Small = 0,
    Normal,
    Medium,
    Large,
    ExtraLarge
}

public enum TextWeight : Int32
{
    case Lighter = 0,
    Normal,
    Bolder
}

public enum TextColor : Int32
{
    case Default = 0,
    Dark,
    Light,
    Accent,
    Good,
    Warning,
    Attention
}

public enum HorizontalAlignment : Int32
{
    case Left = 0,
    Center,
    Right
}

public enum SeperationStyle : Int32
{
    case Default = 0,
    None,
    Strong
}
