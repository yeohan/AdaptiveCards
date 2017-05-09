//
//  AdaptiveCard.swift
//  Sample
//
//  Created by Esteban Chavez on 5/1/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import Foundation

public class AdaptiveCard {
    var objPtr : UnsafeRawPointer
    
    public init() {
        objPtr = AdaptiveCard_Init()
    }
    
    public init(version: String, minVersion: String, fallbackText: String, backgroundImageUrl: String) {
        objPtr = AdaptiveCard_Init2(version, minVersion, fallbackText, backgroundImageUrl)
    }
    
    public init(jsonString: String) {
        objPtr = AdaptiveCard_DeserializeFromString(jsonString)
    }
    
    public var version : String {
        get {
            return String(cString: AdaptiveCard_GetVersion(objPtr))
        }
        set {
            AdaptiveCard_SetVersion(objPtr, newValue)
        }
    }
    
    public var minVersion : String {
        get {
            return String(cString: AdaptiveCard_GetMinVersion(objPtr))
        }
        set {
            AdaptiveCard_SetMinVersion(objPtr, newValue)
        }
    }
    
    public var fallbackText : String {
        get {
            return String(cString: AdaptiveCard_GetFallbackText(objPtr))
        }
        set {
            AdaptiveCard_SetFallbackText(objPtr, newValue)
        }
    }
    
    public var elementType : CardElementType {
        get {
            return CardElementType(rawValue: AdaptiveCard_GetElementType(objPtr))!
        }
    }
    
}
