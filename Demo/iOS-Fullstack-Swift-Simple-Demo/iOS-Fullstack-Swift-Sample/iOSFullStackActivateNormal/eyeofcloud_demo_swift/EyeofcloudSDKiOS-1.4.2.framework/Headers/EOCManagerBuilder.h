/****************************************************************************
 * Copyright 2016-2017, Eyeofcloud, Inc. and contributors                   *
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

@protocol EOCDatafileManager, EOCErrorHandler, EOCEventDispatcher, EOCLogger, EOCUserProfileService;
@class EOCManagerBuilder;

typedef void (^EOCManagerBuilderBlock)(EOCManagerBuilder * _Nullable builder);

@interface EOCManagerBuilder : NSObject

/// The default datafile to initialize an Eyeofcloud Client with before polling the CDN for a datafile
@property (nonatomic, readwrite, strong, nullable) NSData *datafile;
/// The dispatch interval for the event dispatcher.
@property (nonatomic, readwrite) NSTimeInterval eventDispatchInterval;
/// The ID of the Eyeofcloud Project the manager will oversee
@property (nonatomic, readwrite, strong, nonnull) NSString *projectId;
/// The datafile manager to be used for the manager
@property (nonatomic, readwrite, strong, nonnull) id<EOCDatafileManager> datafileManager;
/// The error handler to be used for the manager, client, and all subcomponents
@property (nonatomic, readwrite, strong, nullable) id<EOCErrorHandler> errorHandler;
/// The event dispatcher to initialize an Eyeofcloud Client with
@property (nonatomic, readwrite, strong, nullable) id<EOCEventDispatcher> eventDispatcher;
/// The logger to be used for the manager, client, and all subcomponents
@property (nonatomic, readwrite, strong, nullable) id<EOCLogger> logger;
/// User profile to be used by the client to store user-specific data.
@property (nonatomic, readwrite, strong, nullable) id<EOCUserProfileService> userProfileService;

/// Create the Eyeofcloud Manager object.
+ (nullable instancetype)builderWithBlock:(nonnull EOCManagerBuilderBlock)block;

@end
