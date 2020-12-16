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

extern NSString * _Nonnull const EyeofcloudAppVersionKey;
extern NSString * _Nonnull const EyeofcloudDeviceModelKey;
extern NSString * _Nonnull const EyeofcloudOSVersionKey;
extern NSString * _Nonnull const EyeofcloudSDKVersionKey;

@class EOCClient, EOCManagerBuilder;
@protocol EOCDatafileManager, EOCErrorHandler, EOCEventDispatcher, EOCLogger, EOCUserProfileService;

typedef void (^EOCManagerBuilderBlock)(EOCManagerBuilder * _Nullable builder);

@protocol EOCManager
/**
 * Init with builder block
 * @param builderBlock The Eyeofcloud Manager Builder Block where datafile manager, event dispatcher, and other configurations will be set.
 * @return EyeofcloudManager instance
 */
+ (nullable instancetype)init:(nonnull EOCManagerBuilderBlock)builderBlock;
@end

@interface EOCManagerBase : NSObject
{
@protected
    NSString *_clientEngine;
    NSString *_clientVersion;
}

/// The ID of the Eyeofcloud project to manager
@property (nonatomic, readwrite, strong, nonnull) NSString *projectId;
/// The default datafile to initialize an Eyeofcloud Client with
@property (nonatomic, readwrite, strong, nullable) NSData *datafile;
/// The datafile manager that will download the datafile for the manager
@property (nonatomic, readwrite, strong, nullable) id<EOCDatafileManager> datafileManager;
/// The error handler to be used for the manager, client, and all subcomponents
@property (nonatomic, readwrite, strong, nullable) id<EOCErrorHandler> errorHandler;
/// The event dispatcher to initialize an Eyeofcloud Client with
@property (nonatomic, readwrite, strong, nullable) id<EOCEventDispatcher> eventDispatcher;
/// The logger to be used for the manager, client, and all subcomponents
@property (nonatomic, readwrite, strong, nullable) id<EOCLogger> logger;
/// User profile to be used by the client to store user-specific data.
@property (nonatomic, readwrite, strong, nullable) id<EOCUserProfileService> userProfileService;
/// The client engine
@property (nonatomic, readonly, strong, nonnull) NSString *clientEngine;
/// Version number of the Eyeofcloud iOS SDK
@property (nonatomic, readonly, strong, nonnull) NSString *clientVersion;
/// iOS Device Model
@property (nonatomic, readonly, strong, nonnull) NSString *deviceModel;
/// iOS OS Version
@property (nonatomic, readonly, strong, nonnull) NSString *osVersion;
/// iOS App Version
@property (nonatomic, readonly, strong, nonnull) NSString *appVersion;

/*
 * Synchronous call that would retrieve the datafile from local cache. If it fails to load from local cache it will return a dummy instance
 */
- (nullable EOCClient *)initialize;

/**
 * Synchronous call that would instantiate the client from the datafile given
 * If the datafile is bad, then the client will try to get the datafile from local cache (if it exists). If it fails to load from local cache it will return a dummy instance
 */
- (nullable EOCClient *)initializeWithDatafile:(nonnull NSData *)datafile;


/**
 * Asynchronously gets the client from a datafile downloaded from the CDN.
 * If the client could not be initialized, the error will be set in the callback.
 */
- (void)initializeWithCallback:(void(^ _Nullable)(NSError * _Nullable error, EOCClient * _Nullable client))callback;

/*
 * Gets the cached Eyeofcloud client.
 */
- (nullable EOCClient *)getEyeofcloud;

@end
