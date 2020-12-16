//
//  YFLoginViewModel.h
//  LoginPractice
//
//  Created by Heliyuntong on 2017/5/4.
//  Copyright © 2017年 Heliyuntong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ReactiveObjC/ReactiveObjC.h>

@interface YFLoginViewModel : NSObject

@property (nonatomic,copy)NSString *username;
@property (nonatomic,copy)NSString *password;

@property (nonatomic,strong)RACSignal *loginButtonEnableSignal;
@property (nonatomic,strong)RACCommand *loginCommad;

@end
