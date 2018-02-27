//
//  ACRActionDelegate 
//  ACRActionDelegate.h
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import <Foundation/Foundation.h>

@protocol ACRActionDelegate <NSObject>

- (void)didFetchUserResponses:(NSData *)json error:(NSError *)error;

- (void)didFetchUserResponses:(NSData *)json data:(NSString *)data error:(NSError *)error;

- (void)didFetchHttpRequest:(NSURLRequest *)urlRequest;

@optional
- (void)didCompleteRendering;

@end
