//
//  TextBlock.swift
//  Sample
//
//  Created by Esteban Chavez on 4/14/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import Foundation


public class TextBlock {
    public init(){
        self.objPtr = TextBlock_Initialize();
    }
    
    public init(seperationStyle: SeperationStyle, speak: String, text: String, textSize: TextSize, textWeight: TextWeight, textColor: TextColor, isSubtle: Bool, wrap: Bool, maxLines: Int32, horizontalAlignment: HorizontalAllignment)
    {
        self.objPtr = TextBlock_InitializeWithArgs(seperationStyle.rawValue, speak, text, textSize.rawValue, textWeight.rawValue, textColor.rawValue, isSubtle, wrap, maxLines, horizontalAlignment.rawValue)
    }
    
    public var text : String
    {
        get
        {
            let val : String = String(cString:TextBlock_GetText(objPtr))
            return val
        }
        
        set
        {
            TextBlock_SetText(objPtr, "haha")
        }
    }
    
    var objPtr:UnsafeRawPointer
}
