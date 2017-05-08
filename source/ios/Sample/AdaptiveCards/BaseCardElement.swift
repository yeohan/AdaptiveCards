//
//  BaseCardElement.swift
//  Sample
//
//  Created by Esteban Chavez on 4/26/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import Foundation

public class BaseCardElement {
    var objPtr:UnsafeRawPointer
    
    internal init(object: UnsafeRawPointer){
        objPtr = object
    }
    
    public var seperationStyle: SeperationStyle {
        get {
            return SeperationStyle(rawValue: BaseCardElement_GetSeperationStyle(objPtr))!
        }
        set {
            BaseCardElement_SetSeperationStyle(objPtr, newValue.rawValue)
        }
    }
    
    public var speak : String {
        get {
            return String(cString:BaseCardElement_GetSpeak(objPtr))
        }
        
        set {
            BaseCardElement_SetSpeak(objPtr, newValue)
        }
    }
    
    public var elementType : AdaptiveCardSchemaKey {
        get {
            return AdaptiveCardSchemaKey(rawValue: BaseCardElement_GetElementType(objPtr))!
        }
    }
}
