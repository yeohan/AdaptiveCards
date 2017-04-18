//
//  TextBlock.swift
//  Sample
//
//  Created by Esteban Chavez on 4/14/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import Foundation

class TextBlock {
    init(){
        self.objPtr = initialize();
    }
    
    var objPtr:UnsafeRawPointer
}
