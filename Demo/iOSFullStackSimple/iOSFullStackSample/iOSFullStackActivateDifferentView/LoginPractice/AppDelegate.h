//
//  AppDelegate.h
//  LoginPractice
//
//  Created by Heliyuntong on 2017/5/4.
//  Copyright © 2017年 Heliyuntong. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <EyeofcloudSDKiOS/EyeofcloudSDKiOS.h>

@interface AppDelegate : UIResponder <UIApplicationDelegate>

@property (strong, nonatomic) UIWindow *window;

- (EOCManager *)getEOCManager;

- (EOCClient *)getEyeofcloud;

- (NSString *)getUserId;

- (NSDictionary *)getUserAttributes;

@end

