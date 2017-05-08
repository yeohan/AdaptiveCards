//
//  TextBlock.swift
//  Sample
//
//  Created by Esteban Chavez on 4/14/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import Foundation


public class TextBlock: BaseCardElement {
    public init(){
        super.init(object: TextBlock_Initialize())
    }
    
    public init(seperationStyle: SeperationStyle, speak: String, text: String, textSize: TextSize, textWeight: TextWeight, textColor: TextColor, isSubtle: Bool, wrap: Bool, maxLines: Int32, horizontalAlignment: HorizontalAllignment)
    {
        super.init(object: TextBlock_InitializeWithArgs(seperationStyle.rawValue, speak, text, textSize.rawValue, textWeight.rawValue, textColor.rawValue, isSubtle, wrap, maxLines, horizontalAlignment.rawValue))
    }
    
    public var text : String
    {
        get
        {
            return String(cString:TextBlock_GetText(objPtr))
        }
        
        set
        {
            TextBlock_SetText(objPtr, newValue)
        }
    }
    
    public var textSize : TextSize {
        get {
            return TextSize(rawValue: TextBlock_GetTextSize(objPtr))!
        }
        set {
            TextBlock_SetTextSize(objPtr, newValue.rawValue)
        }
    }
    
    public var textWeight : TextWeight {
        get {
            return TextWeight(rawValue: TextBlock_GetTextWeight(objPtr))!
        }
        set {
            TextBlock_SetTextWeight(objPtr, newValue.rawValue);
        }
    }
    
    public var textColor : TextColor {
        get {
            return TextColor(rawValue: TextBlock_GetTextColor(objPtr))!
        }
        set {
            TextBlock_SetTextColor(objPtr, newValue.rawValue);
        }
    }
    
    public var wrap : Bool {
        get {
            return TextBlock_GetWrap(objPtr)
        }
        set {
            TextBlock_SetWrap(objPtr, newValue)
        }
    }
    
    public var isSubtle : Bool {
        get {
            return TextBlock_GetIsSubtle(objPtr)
        }
        set {
            TextBlock_SetIsSubtle(objPtr, newValue)
        }
    }
    
    public var maxLines : Int32 {
        get {
            return TextBlock_GetMaxLines(objPtr)
        }
        set {
            TextBlock_SetMaxLines(objPtr, newValue)
        }
    }
    
    public var horizontalAlignment : HorizontalAllignment {
        get {
            return HorizontalAllignment(rawValue: TextBlock_GetHorizontalAlignment(objPtr))!
        }
        set {
            TextBlock_SetHorizontalAlignment(objPtr, newValue.rawValue)
        }
    }
}
