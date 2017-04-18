//
//  TextBlockBridge.h
//  Sample
//
//  Created by Esteban Chavez on 4/14/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

#ifndef TextBlockBridge_h
#define TextBlockBridge_h

#ifdef __cplusplus
extern "C" {
#endif
    
    const void *initialize();
    const void *initializeWithArgs(
        char *speak,
        char *text,
        int textSize,
        int textWeight,
        int textColor,
        bool isSubtle,
        bool wrap,
        bool maxLines,
        int horizontalAlignment
    );

#ifdef __cplusplus
}
#endif



#endif /* TextBlockBridge_h */
