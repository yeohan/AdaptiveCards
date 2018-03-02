//
//  ACRContainerRenderer
//  ACRContainerRenderer.mm
//
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ACRContainerRenderer.h"
#import "ACRColumnView.h"
#import "ACRRendererPrivate.h"
#import "Container.h"
#import "SharedAdaptiveCard.h"
#import "ACRLongPressGestureRecognizerFactory.h"
#import "ACOHostConfigPrivate.h"
#import "ACOBaseCardElementPrivate.h"

@implementation ACRContainerRenderer

+ (ACRContainerRenderer *)getInstance
{
    static ACRContainerRenderer *singletonInstance = [[self alloc] init];
    return singletonInstance;
}

+ (ACRCardElementType)elemType
{
    return ACRContainer;
}

- (UIView *)render:(UIView<ACRIContentHoldingView> *)viewGroup
rootViewController:(UIViewController *)vc
            inputs:(NSMutableArray *)inputs
   baseCardElement:(ACOBaseCardElement *)acoElem
        hostConfig:(ACOHostConfig *)acoConfig;
{
    std::shared_ptr<HostConfig> config = [acoConfig getHostConfig];
    std::shared_ptr<BaseCardElement> elem = [acoElem element];
    std::shared_ptr<Container> containerElem = std::dynamic_pointer_cast<Container>(elem);

    ACRColumnView *container = [[ACRColumnView alloc] initWithStyle:(ACRContainerStyle)containerElem->GetStyle()
                                                        parentStyle:[viewGroup style] hostConfig:acoConfig];
    [ACRRenderer render:container
     rootViewController:vc
                 inputs:inputs
          withCardElems:containerElem->GetItems()
          andHostConfig:config];

    [[container layer] setCornerRadius:20]; // tentative change to make rounded corner

    [viewGroup addArrangedSubview:container];

    std::shared_ptr<BaseActionElement> selectAction = containerElem->GetSelectAction();
    // instantiate and add tap gesture recognizer
    UILongPressGestureRecognizer * gestureRecognizer =
        [ACRLongPressGestureRecognizerFactory getLongPressGestureRecognizer:viewGroup
                                                         rootViewController:vc
                                                                 targetView:container
                                                              actionElement:selectAction
                                                                     inputs:inputs
                                                                 hostConfig:config];
    if(gestureRecognizer)
    {
        [container addGestureRecognizer:gestureRecognizer];
        container.userInteractionEnabled = YES;
    }
    return viewGroup;
}

@end

