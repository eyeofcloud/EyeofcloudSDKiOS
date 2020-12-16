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

@class EOCBucketer, EOCEventBuilder, EOCEventBuilderDefault, EOCProjectConfig;
@protocol EOCDatafileManager, EOCErrorHandler, EOCEventBuilder, EOCEventDispatcher, EOCLogger, EOCUserProfileService;

/**
 * This class contains the information on how your Eyeofcloud instance will be built.
 */

@class EOCBuilder;

/// This is a block that takes the builder values.
typedef void (^EOCBuilderBlock)(EOCBuilder * _Nullable builder);

@interface EOCBuilder: NSObject

/// A datafile is required to create an Eyeofcloud object.
@property (nonatomic, readwrite, strong, nullable) NSData *datafile;
/// The Project Configuration created by the builder.
@property (nonatomic, readonly, strong, nullable) EOCProjectConfig *config;
/// The bucketer created by the builder.
@property (nonatomic, readonly, strong, nullable) EOCBucketer *bucketer;
/// The event builder created by the builder.
@property (nonatomic, readonly, strong, nullable) EOCEventBuilderDefault *eventBuilder;
/// The error handler is by default set to one that is created by Eyeofcloud. This default error handler can be overridden by any object that conforms to the EOCErrorHandler protocol.
@property (nonatomic, readwrite, strong, nullable) id<EOCErrorHandler> errorHandler;
/// The event dispatcher is by default set to one that is created by Eyeofcloud. This default event dispatcher can be overridden by any object that conforms to the EOCEventDispatcher protocol.
@property (nonatomic, readwrite, strong, nullable) id<EOCEventDispatcher> eventDispatcher;
/// The logger is by default set to one that is created by Eyeofcloud. This default logger can be overridden by any object that conforms to the EOCLogger protocol.
@property (nonatomic, readwrite, strong, nullable) id<EOCLogger> logger;
/// User profile stores user-specific data, like bucketing.
@property (nonatomic, readwrite, strong, nullable) id<EOCUserProfileService> userProfileService;
/// The datafile manager that will download the datafile for the manager
@property (nonatomic, readwrite, strong, nullable) id<EOCDatafileManager> datafileManager;
/// The client version
@property (nonatomic, strong, nonnull) NSString *clientVersion;
/// The client engine
@property (nonatomic, strong, nonnull) NSString *clientEngine;


/// Create an Eyeofcloud Builder object.
+ (nullable instancetype)builderWithBlock:(nonnull EOCBuilderBlock)block;

@end
