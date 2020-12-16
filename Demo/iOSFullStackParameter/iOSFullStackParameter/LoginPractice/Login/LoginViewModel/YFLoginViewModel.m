//
//  YFLoginViewModel.m
//  LoginPractice
//
//  Created by Heliyuntong on 2017/5/4.
//  Copyright © 2017年 Heliyuntong. All rights reserved.
//

#import "YFLoginViewModel.h"
#import "YFFirstPageViewController.h"
#import <SVProgressHUD.h>


@interface YFLoginViewModel ()


@end

@implementation YFLoginViewModel

#pragma mark - init
- (instancetype)init {
    if (self = [super init]) {
        [self setup];
    }
    return self;
}

- (void)setup {
    self.loginButtonEnableSignal = [RACSignal combineLatest:@[RACObserve(self, username), RACObserve(self, password)] reduce:^id(NSString *username, NSString *password){
        return @(username.length && password.length);
    }];
    
    self.loginCommad = [[RACCommand alloc] initWithSignalBlock:^RACSignal * _Nonnull(id input) {
        return [RACSignal createSignal:^RACDisposable * _Nullable(id<RACSubscriber>  _Nonnull subscriber) {
            NSMutableURLRequest *request = [NSMutableURLRequest requestWithURL:[NSURL URLWithString:@"http://120.25.226.186:32812/login"]];
            request.HTTPMethod = @"POST";
            NSString *paramString = [NSString stringWithFormat:@"username=%@&pwd=%@&type=JSON", self.username, self.password];
            NSData *paramData = [paramString dataUsingEncoding:NSUTF8StringEncoding];
            request.HTTPBody = paramData;
            NSURLSessionConfiguration *sessionConfig=[NSURLSessionConfiguration defaultSessionConfiguration];
            [sessionConfig setTimeoutIntervalForRequest:3.0f];
            NSURLSession *urlSession=[NSURLSession sessionWithConfiguration:sessionConfig delegate:self delegateQueue:[NSOperationQueue mainQueue]];
            //[NSURLSession sharedSession]
            [[urlSession dataTaskWithRequest:request completionHandler:^(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error) {
//                NSDictionary *resultDictionary = [NSJSONSerialization JSONObjectWithData:data options:kNilOptions error:NULL];
                NSDictionary *resultDictionary = @{@"key1":@"Eezy",@"success": @"ok"};
                [subscriber sendNext:resultDictionary];
                /****************** -------- 发送完成这一步很重要, 不然后面的无法信号无法执行 -------- ******************/
                [subscriber sendCompleted];
            }] resume];
            return nil;
        }];
    }];
    
    [self.loginCommad.executionSignals.switchToLatest subscribeNext:^(NSDictionary *x) {
        if ([x.allKeys.lastObject isEqualToString:@"success"]) {
            [SVProgressHUD showSuccessWithStatus:@"登录成功"];
            [SVProgressHUD dismissWithDelay:1 completion:^{
                YFFirstPageViewController *firstPageVC = [[YFFirstPageViewController alloc] init];
                [UIView animateWithDuration:1 animations:^{
                    [UIApplication sharedApplication].keyWindow.rootViewController = firstPageVC;
                }];
            }];
        }else {
            [SVProgressHUD showErrorWithStatus:@"登录失败"];
            [SVProgressHUD dismissWithDelay:1];
        }
    }];
    
    [[self.loginCommad.executing skip:1] subscribeNext:^(NSNumber * _Nullable x) {
        if ([x boolValue]) {
            [SVProgressHUD showWithStatus:@"正在登录中"];
        }
    }];
}

@end
