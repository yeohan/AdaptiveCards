//
//  TextBlockBridge.cpp
//  Sample
//
//  Created by Esteban Chavez on 4/14/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

#include <stdio.h>
#include "TextBlock.h"

using namespace std;

const void * initialize
(
)
{
    AdaptiveCards::TextBlock *textBlock = new AdaptiveCards::TextBlock();
    
    return (void *)textBlock;
}

const void * initializeWithArgs
(
 char *speak,
 char *text,
 int textSize,
 int textWeight,
 int textColor,
 bool isSubtle,
 bool wrap,
 bool maxLines,
 int horizontalAlignment
)
{
    
    AdaptiveCards::TextBlock *textBlock = new AdaptiveCards::TextBlock();
    
    return (void *)textBlock;
}
