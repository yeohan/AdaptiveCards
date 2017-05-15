//
//  UIRendererTest.swift
//  UIRendererTest
//
//  Created by jwoo on 5/9/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

import XCTest
import AdaptiveCards

class UIRendererTest: XCTestCase {
    
    var disp: InfoDisplayBuilder!
    override func setUp() {
        super.setUp()
        disp = InfoDisplayBuilder()
        // Put setup code here. This method is called before the invocation of each test method in the class.
    }
    
    override func tearDown() {
        // Put teardown code here. This method is called after the invocation of each test method in the class.
        super.tearDown()
    }
    
    func testExample() {
        // This is an example of a functional test case.
        // Use XCTAssert and related functions to verify your tests produce the correct results.
    }
    
    func testPerformanceExample() {
        // This is an example of a performance test case.
        self.measure {
            // Put the code you want to measu¨re the time of here.
        }
    }
    
    func testAdaptiveTextBlockInit() {
        let aTextBlock:TextBlock = TextBlock();
        let aTextBlock2:TextBlock = TextBlock(seperationStyle: SeperationStyle.None, speak: "Hello", text: "World", textSize: TextSize.Normal, textWeight: TextWeight.Normal, textColor: TextColor.Dark, isSubtle: true, wrap: false, maxLines: 50, horizontalAlignment:HorizontalAlignment.Left);
        XCTAssert(aTextBlock.isSubtle == false);
        XCTAssert(aTextBlock2.isSubtle == true);
        
    }
    
    func testCanInitInfoDisplayBuilder()
    {
        let localdisp:InfoDisplayBuilder = InfoDisplayBuilder();
        //let aTextBlock2:TextBlock = TextBlock(seperationStyle: SeperationStyle.None, speak: "Hello", text: "World", textSize: TextSize.Normal, textWeight: TextWeight.Normal, textColor: TextColor.Dark, isSubtle: true, wrap: false, maxLines: 50, horizontalAlignment:HorizontalAlignment.Left);
    }

    func testBuildTextBlockExist()
    {
        IAdaptiveCardElement*
        disp.BuildTextBlock();
    }
}
