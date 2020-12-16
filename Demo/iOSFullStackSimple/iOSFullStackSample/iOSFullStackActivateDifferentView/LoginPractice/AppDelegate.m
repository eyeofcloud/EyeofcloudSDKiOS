//
//  AppDelegate.m
//  LoginPractice
//
//  Created by Heliyuntong on 2017/5/4.
//  Copyright © 2017年 Heliyuntong. All rights reserved.
//

#import "AppDelegate.h"
#import "YFLoginViewController.h"

@interface AppDelegate ()

@property (strong, nonatomic, readonly) EOCManager *eocManager;

@property (strong, nonatomic, readonly) NSString *userId;

@property (strong, nonatomic, readonly) NSDictionary *userAttributes;

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
    // 设置根视图控制器
    self.window = [[UIWindow alloc] initWithFrame:UIScreen.mainScreen.bounds];
    
    UIViewController *fakeRootViewController = [[UIViewController alloc] init];
    UIImageView *imageView = [[UIImageView alloc] initWithFrame:UIScreen.mainScreen.bounds];
    [imageView setImage:[UIImage imageNamed:@"LaunchImage.png"]];
    fakeRootViewController.view = imageView;
    
    self.window.rootViewController = fakeRootViewController;
    [self.window makeKeyAndVisible];
    
    // 初始化EOCManager
    _eocManager = [EOCManager init:^(EOCManagerBuilder * _Nullable builder) {
        builder.projectId = @"8_3e9f2898e924f4961afb27b57ee7da08";
    }];
    
    // 异步网络下载配置文件，请求超时时间为5s
    [_eocManager initializeWithCallback:^(NSError * _Nullable error, EOCClient * _Nullable client) {
        // 防止APP在没有网络连接的情况下启动实验失败
        if (!client.eyeofcloud) {
            client = [_eocManager initialize];
            if (!client.eyeofcloud) {
                NSString *datafilePath = [[NSBundle mainBundle] pathForResource:@"datafile" ofType:@"json"];
                client = [_eocManager initializeWithDatafile:[NSData dataWithContentsOfFile:datafilePath]];
            }
        }
        // 完成下载及版本抽签，根据抽签结果创建不同版本的View，最后更新主界面
        dispatch_async(dispatch_get_main_queue(), ^{
            EOCVariation *variation = [client activate:@"iOS-param" userId:[self getUserId] attributes:[self getUserAttributes]];
            YFLoginViewController *loginViewController = [[YFLoginViewController alloc] init];
            if ([variation.variationKey isEqualToString:@"优化版本#1"]) {
                loginViewController.view.backgroundColor = [UIColor orangeColor];
            }
            self.window.rootViewController = loginViewController;
        });
    }];
    
    return YES;
}

- (EOCManager *)getEOCManager {
    return _eocManager;
}

- (EOCClient *)getEyeofcloud {
    return [_eocManager getEyeofcloud];
}

- (NSString *)getUserId {
    if (!_userId) {
        _userId = [[[UIDevice currentDevice] identifierForVendor] UUIDString];
    }
    return _userId;
}

- (NSDictionary *)getUserAttributes {
    if (!_userAttributes) {
        _userAttributes = @{@"Gender":@"male"};
    }
    return _userAttributes;
}

- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationDidBecomeActive:(UIApplication *)application {
    // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}


@end
