//
//  YFFirstPageViewController.m
//  LoginPractice
//
//  Created by Heliyuntong on 2017/5/4.
//  Copyright © 2017年 Heliyuntong. All rights reserved.
//

#import "YFFirstPageViewController.h"
#import "AppDelegate.h"

@interface YFFirstPageViewController ()

@end

@implementation YFFirstPageViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupUI];
}

- (void)buttonPressed:(UIButton *)button {
    AppDelegate *delegateClass = (AppDelegate*)[[UIApplication sharedApplication]delegate];
    EOCClient *eocClient = [delegateClass getEyeofcloud];
    NSString *userId = [delegateClass getUserId];
    NSDictionary * userAttributes = [delegateClass getUserAttributes];
    [eocClient track:@"用户点击按钮" userId:userId attributes:userAttributes];
    
    NSString *msessage_str = @"UserID: ";
    msessage_str = [msessage_str stringByAppendingString:userId];
    UIAlertController *alert = [UIAlertController alertControllerWithTitle:@"目标事件：用户点击按钮\n已发送" message:msessage_str preferredStyle:UIAlertControllerStyleAlert];

    UIAlertAction *cancel = [UIAlertAction actionWithTitle:@"Dismiss" style:UIAlertActionStyleCancel handler:nil];
    [alert addAction:cancel];
    [self presentViewController:alert animated:YES completion:nil];
    
    double delayInSeconds = 3; // set the time
    dispatch_time_t popTime = dispatch_time(DISPATCH_TIME_NOW, delayInSeconds * NSEC_PER_SEC);
    dispatch_after(popTime, dispatch_get_main_queue(), ^(void){
        [self dismissViewControllerAnimated:YES completion:nil];
    });
}

- (void)setupUI {
    self.view.backgroundColor = [UIColor yellowColor];
    UILabel *label = [[UILabel alloc] initWithFrame:CGRectMake(0, 0, 200, 40)];
    label.textAlignment = NSTextAlignmentCenter;
    label.center = CGPointMake(self.view.center.x, self.view.center.y*2/3);
    
    AppDelegate *delegateClass = (AppDelegate*)[[UIApplication sharedApplication]delegate];

    EOCClient *eocClient = [delegateClass getEyeofcloud];
    NSString *userId = [delegateClass getUserId];
    NSDictionary * userAttributes = [delegateClass getUserAttributes];
    
    EOCVariation * variation = [eocClient activate:@"iOS-param" userId:userId attributes:userAttributes];

    if ([variation.variationKey isEqualToString:@"优化版本#1"]) {
        label.text = @"版本A优化界面";
    }else if([variation.variationKey isEqualToString:@"原始版本"]){
        label.text = @"版本A界面";
    }else{
        label.text = @"版本A界面";
    }

    [self.view addSubview:label];
    
    UIButton *button = [UIButton buttonWithType:UIButtonTypeSystem];
    [button setTitle:@"发送目标事件" forState:UIControlStateNormal];
    [button sizeToFit];
    
    button.center =  CGPointMake(self.view.center.x, self.view.center.y*8/5);
    
    
    // Add an action in current code file (i.e. target)
    [button addTarget:self action:@selector(buttonPressed:)
         forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:button];
}


@end
