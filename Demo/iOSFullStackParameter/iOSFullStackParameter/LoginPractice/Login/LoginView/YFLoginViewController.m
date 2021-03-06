//
//  YFLoginViewController.m
//  LoginPractice
//
//  Created by Heliyuntong on 2017/5/4.
//  Copyright © 2017年 Heliyuntong. All rights reserved.
//

#import "YFLoginViewController.h"
#import "YFLoginView.h"
#import "YFLoginViewModel.h"
#import <ReactiveObjC/ReactiveObjC.h>
#import "AppDelegate.h"
#import <EyeofcloudSDKiOS/EyeofcloudSDKiOS.h>

@interface YFLoginViewController ()

@property (nonatomic, strong) YFLoginView *loginView;
@property (nonatomic, strong) YFLoginViewModel *loginViewModel;
@property (nonatomic, strong) EOCClient *eocClient;
@property (nonatomic, strong) NSString *userId;
@property (nonatomic, strong) NSDictionary *userAttributes;

@end

@implementation YFLoginViewController

#pragma mark - life cycle
- (void)loadView {
    self.loginView = [[YFLoginView alloc] init];
    self.view = _loginView;
    
    // Eyeofcloud
    AppDelegate *delegate = (AppDelegate *)[[UIApplication sharedApplication] delegate];
    self.eocClient = [[delegate getEOCManager] getEyeofcloud];
    self.userId = [delegate getUserId];
    self.userAttributes = [delegate getUserAttributes];
    
    NSString *accoutPlaceHolder = [self.eocClient variableString:@"LoginAccountPlaceHolder" userId:self.userId attributes:self.userAttributes activateExperiment:true];
    if (accoutPlaceHolder) {
        _loginView.usernameTextField.placeholder = accoutPlaceHolder;
    }
    NSString *passwordPlaceHolder = [self.eocClient variableString:@"LoginPasswordPlaceHolder" userId:self.userId attributes:self.userAttributes activateExperiment:true];
    if (passwordPlaceHolder) {
        _loginView.passwordTextField.placeholder = passwordPlaceHolder;
    }
}

- (void)viewDidLoad {
    [super viewDidLoad];
    [self loginButtonEnable];
    [self loginButtonAction];
}

#pragma mark - events && actions

- (void)loginButtonEnable {
    RAC(self.loginViewModel, username) = _loginView.usernameTextField.rac_textSignal;
    RAC(self.loginViewModel, password) = _loginView.passwordTextField.rac_textSignal;
    RAC(self.loginView.loginButton, enabled) = _loginViewModel.loginButtonEnableSignal;
}

- (void)loginButtonAction {
    [[_loginView.loginButton rac_signalForControlEvents:UIControlEventTouchUpInside] subscribeNext:^(__kindof UIControl * _Nullable x) {
        [self.eocClient track:@"用户点击按钮" userId:self.userId attributes:self.userAttributes];
        [self.loginViewModel.loginCommad execute:nil];
    }];
}

#pragma mark - lazy initialization
- (YFLoginViewModel *)loginViewModel {
    if (!_loginViewModel) {
        _loginViewModel = [[YFLoginViewModel alloc] init];
    }
    return _loginViewModel;
}

@end
