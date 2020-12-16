/****************************************************************************
 * Copyright 2016, Eyeofcloud, Inc. and contributors                        *
 *                                                                          *
 * Licensed under the Apache License, Version 2.0 (the "License");          *
 * you may not use this file except in compliance with the License.         *
 * You may obtain a copy of the License at                                  *
 *                                                                          *
 *    http://www.apache.org/licenses/LICENSE-2.0                            *
 *                                                                          *
 * Unless required by applicable law or agreed to in writing, software      *
 * distributed under the License is distributed on an "AS IS" BASIS,        *
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. *
 * See the License for the specific language governing permissions and      *
 * limitations under the License.                                           *
 ***************************************************************************/

#import <Foundation/Foundation.h>

@class Eyeofcloud, EOCProjectConfig, EOCBucketer, EOCEventBuilder, EOCEventBuilderDefault;
@protocol EOCErrorHandler, EOCEventBuilder, EOCEventDispatcher, EOCLogger, EOCUserProfileService;

/**
 * This class contains the informaation on how your Eyeofcloud Client instance will be built.
 */
@class EOCClientBuilder;

/// This is a block that takes the builder values.
typedef void (^EOCClientBuilderBlock)(EOCClientBuilder * _Nonnull builder);

@interface EOCClientBuilder : NSObject

/// Reference to the Eyeofcloud Core instance
@property (nonatomic, readonly, strong, nullable) Eyeofcloud *eyeofcloud;
/// A datafile is required to create an Eyeofcloud object.
@property (nonatomic, readwrite, strong, nullable) NSData *datafile;
/// The error handler is by default set to one that is created by Eyeofcloud. This default error handler can be overridden by any object that conforms to the EOCErrorHandler protocol.
@property (nonatomic, readwrite, strong, nullable) id<EOCErrorHandler> errorHandler;
/// The event dispatcher is by default set to one that is created by Eyeofcloud. This default event dispatcher can be overridden by any object that conforms to the EOCEventDispatcher protocol.
@property (nonatomic, readwrite, strong, nullable) id<EOCEventDispatcher> eventDispatcher;
/// The logger is by default set to one that is created by Eyeofcloud. This default logger can be overridden by any object that conforms to the EOCLogger protocol.
@property (nonatomic, readwrite, strong, nullable) id<EOCLogger> logger;
/// User profile to be used by the Eyeofcloud instance to store user-specific data.
@property (nonatomic, readwrite, strong, nullable) id<EOCUserProfileService> userProfileService;
/// The client version
@property (nonatomic, strong, nonnull) NSString *clientVersion;
/// The client engine
@property (nonatomic, strong, nonnull) NSString *clientEngine;

/// Create an Eyeofcloud Client object.
+ (nonnull instancetype)builderWithBlock:(nonnull EOCClientBuilderBlock)block;

@end
