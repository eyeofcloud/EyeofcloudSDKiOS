//
//  YFLoginView.m
//  LoginPractice
//
//  Created by Heliyuntong on 2017/5/4.
//  Copyright © 2017年 Heliyuntong. All rights reserved.
//

#import "YFLoginView.h"
#import <Masonry.h>


@interface YFLoginView ()

@property (nonatomic,strong)UILabel *usernameLabel;
@property (nonatomic,strong)UILabel *passwordLabel;

@property (nonatomic,strong)UIView *usernameTextLine;
@property (nonatomic,strong)UIView *passwordTextLine;

@end

@implementation YFLoginView

#pragma mark - init
- (instancetype)init {
    if (self = [super init]) {
        [self setupUI];
    }
    return self;
}

#pragma mark - lazy initialization

- (UIView *)usernameTextLine {
    if (!_usernameTextLine) {
        _usernameTextLine = [[UIView alloc] init];
        _usernameTextLine.backgroundColor = [UIColor lightGrayColor];
    }
    return _usernameTextLine;
}

- (UIView *)passwordTextLine {
    if (!_passwordTextLine) {
        _passwordTextLine = [[UIView alloc] init];
        _passwordTextLine.backgroundColor = [UIColor lightGrayColor];
    }
    return _passwordTextLine;
}

- (UILabel *)usernameLabel {
    if (!_usernameLabel) {
        _usernameLabel = [[UILabel alloc] init];
        _usernameLabel.text = @"账号";
        _usernameLabel.textColor = [UIColor darkGrayColor];
        _usernameLabel.textAlignment = NSTextAlignmentCenter;
        
    }
    return _usernameLabel;
}

- (UILabel *)passwordLabel {
    if (!_passwordLabel) {
        _passwordLabel = [[UILabel alloc] init];
        _passwordLabel.text = @"密码";
        _passwordLabel.textColor = [UIColor darkGrayColor];
        _passwordLabel.textAlignment = NSTextAlignmentCenter;
    }
    return _passwordLabel;
}

- (UITextField *)usernameTextField {
    if (!_usernameTextField) {
        _usernameTextField = [[UITextField alloc] init];
        _usernameTextField.placeholder = @"请输入账号";
        _usernameTextField.clearButtonMode = UITextFieldViewModeWhileEditing;
    }
    return _usernameTextField;
}

- (UITextField *)passwordTextField {
    if (!_passwordTextField) {
        _passwordTextField = [[UITextField alloc] init];
        _passwordTextField.placeholder = @"请输入密码";
        _passwordTextField.clearButtonMode = UITextFieldViewModeWhileEditing;
        _passwordTextField.secureTextEntry = YES;
    }
    return _passwordTextField;
}

- (UIButton *)loginButton {
    if (!_loginButton) {
        _loginButton = [UIButton buttonWithType:UIButtonTypeCustom];
        _loginButton.backgroundColor = [UIColor colorWithRed:0.29 green:0.73 blue:0.97 alpha:1.00];
        _loginButton.layer.cornerRadius = 10;
        _loginButton.layer.masksToBounds = YES;
        [_loginButton setTitle:@"登   录" forState:UIControlStateNormal];
        [_loginButton setTitleColor:[UIColor whiteColor] forState:UIControlStateNormal];
        [_loginButton setTitleColor:[UIColor lightGrayColor] forState:UIControlStateHighlighted];
        [_loginButton setTitleColor:[UIColor lightGrayColor] forState:UIControlStateDisabled];
        _loginButton.enabled = NO;
    }
    return _loginButton;
}

#pragma mark - layout subviews && setup UI 

- (void)setupUI {
    self.backgroundColor = [UIColor whiteColor];
    [self addSubview:self.usernameLabel];
    [self addSubview:self.passwordLabel];
    [self addSubview:self.usernameTextField];
    [self addSubview:self.passwordTextField];
    [self addSubview:self.loginButton];
    [self addSubview:self.usernameTextLine];
    [self addSubview:self.passwordTextLine];
}

- (void)layoutSubviews {
    [self.usernameLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo(60);
        make.top.mas_equalTo(self).offset(120);
        make.left.mas_equalTo(self).offset(60);
    }];
    
    [self.usernameTextField mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.mas_equalTo(_usernameLabel.mas_centerY);
        make.left.mas_equalTo(_usernameLabel.mas_right).offset(10);
        make.right.mas_equalTo(self).offset(-60);
    }];
    
    [self.usernameTextLine mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo(_usernameTextField);
        make.height.mas_equalTo(1);
        make.leading.mas_equalTo(_usernameTextField);
        make.top.mas_equalTo(_usernameTextField.mas_bottom);
    }];
    
    [self.passwordLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo(_usernameLabel);
        make.top.mas_equalTo(_usernameLabel.mas_bottom).offset(80);
        make.leading.mas_equalTo(_usernameLabel);
    }];
    
    [self.passwordTextField mas_makeConstraints:^(MASConstraintMaker *make) {
        make.centerY.mas_equalTo(_passwordLabel.mas_centerY);
        make.left.mas_equalTo(_passwordLabel.mas_right).offset(10);
        make.trailing.mas_equalTo(_usernameTextField);
    }];
    
    [self.passwordTextLine mas_makeConstraints:^(MASConstraintMaker *make) {
        make.width.mas_equalTo(_passwordTextField);
        make.height.mas_equalTo(1);
        make.leading.mas_equalTo(_passwordTextField);
        make.top.mas_equalTo(_passwordTextField.mas_bottom);
    }];
    
    [self.loginButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.top.mas_equalTo(_passwordTextLine.mas_bottom).offset(100);
        make.height.mas_equalTo(44);
        make.leading.mas_equalTo(_passwordLabel).offset(10);
        make.trailing.mas_equalTo(_passwordTextLine);
    }];
}


@end
