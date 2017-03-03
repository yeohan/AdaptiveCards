//
//  ViewController.m
//  adaptive-cards-visualizer
//
//  Created by Ricardo Arenas on 2/18/17.
//  Copyright © 2017 Microsoft. All rights reserved.
//

#import "ViewController.h"
#import "ACDjinniTextBlock.h"

@interface ViewController ()

@end

@implementation ViewController {
    ACDjinniTextBlock *_djinniTextBlock;
    UIButton *_button;
    UITextView *_textView;
    UITextView *_textField;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // create a textField to hold the json
    _textField = [[UITextView alloc] initWithFrame:CGRectMake(20.0, 20.0, 280.0, 100.0)];
    _textField.text = @"{\n"
                        "\"@type\": \"TextBlock\",\n"
                        "\"text\": \"Hello, World!\",\n"
                        "\"speak\": \"My Speak\",\n"
                        "\"size\": \"medium\"\n"
                        "}\n";
    
    [self.view addSubview:_textField];
    
    // create a button programatically for the demo
    _button = [UIButton buttonWithType:UIButtonTypeRoundedRect];
    [_button addTarget:self action:@selector(buttonWasPressed:) forControlEvents:UIControlEventTouchUpInside];
    [_button setTitle:@"Parse TextBlock" forState:UIControlStateNormal];
    _button.frame = CGRectMake(20.0, 150.0, 280.0, 40.0);
    [self.view addSubview:_button];
    
    // create a text view programatically
    _textView = [[UITextView alloc] init];
    _textView.editable = NO;
    // x, y, width, height
    _textView.frame = CGRectMake(20.0, 200.0, 280.0, 380.0);
    [self.view addSubview:_textView];
    
}

- (void)buttonWasPressed:(UIButton*)sender
{
    // instantiate our library interface
    _djinniTextBlock = [ACDjinniTextBlock Deserialize:_textField.text];
    NSString *response = [_djinniTextBlock GetText];
    _textView.text = [NSString stringWithFormat:@"%@\n%@", response, _textView.text];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

@end
