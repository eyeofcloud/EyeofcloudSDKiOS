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

/**
 * This class contains details related to how the Eyeofcloud Project Config instance is built.
 */

@class EOCProjectConfigBuilder;
@protocol EOCErrorHandler, EOCLogger, EOCUserProfileService;

/// This is a block that takes the builder values.
typedef void (^EOCProjectConfigBuilderBlock)(EOCProjectConfigBuilder * _Nullable builder);

@interface EOCProjectConfigBuilder : NSObject

/**
 * Initializer for Eyeofcloud Project Config Builder object
 *
 * @param block The builder block with which to initialize the Eyeofcloud Project Config Builder object
 * @return An instance of EOCProjectConfigBuilder
 */
+ (nullable instancetype)builderWithBlock:(nonnull EOCProjectConfigBuilderBlock)block;

/// optional error handler
@property (nonatomic, strong, nullable) id<EOCErrorHandler> errorHandler;
/// optional logger
@property (nonatomic, strong, nullable) id<EOCLogger> logger;
/// optional user profile
@property (nonatomic, strong, nullable) id<EOCUserProfileService> userProfileService;
/// the non optional datafile contents
@property (nonatomic, strong, nonnull) NSData *datafile;
/// The client version
@property (nonatomic, strong, nonnull) NSString *clientVersion;
/// The client engine
@property (nonatomic, strong, nonnull) NSString *clientEngine;


@end
