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
#import "EOCUserProfileServiceBuilder.h"

@protocol EOCLogger, EOCUserProfileService;

@interface EOCUserProfileServiceDefault : NSObject<EOCUserProfileService>

/// Logger provided by the user
@property (nonatomic, strong, nullable) id<EOCLogger> logger;

/**
 * Initializer for Eyeofcloud User Profile object
 *
 * @param builderBlock The builder block with which to initialize the Eyeofcloud User Profile object
 * @return An instance of EOCUserProfileService
 */
+ (nullable instancetype)init:(nonnull EOCUserProfileServiceBuilderBlock)builderBlock;

/**
 * Cleans and removes all bucketing mapping for specific userId.
 * @param userId The user ID to remove all bucketing value.
 **/
- (void)removeUserExperimentRecordsForUserId:(nonnull NSString *)userId;

/**
 * Cleans and removes all bucketing mapping.
 **/
- (void)removeAllUserExperimentRecords;

@end
