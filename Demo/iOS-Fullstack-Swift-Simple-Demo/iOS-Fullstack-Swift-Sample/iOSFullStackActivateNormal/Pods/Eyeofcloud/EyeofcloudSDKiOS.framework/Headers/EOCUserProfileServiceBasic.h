/****************************************************************************
 * Copyright 2016-2017, Eyeofcloud, Inc. and contributors                        *
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

@protocol EOCUserProfileService <NSObject>

/**
 * Returns a user entity corresponding to the user ID.
 *
 * @param userId The user id to get the user entity of.
 * @returns A dictionary of the user profile details.
 **/
- (nullable NSDictionary *)lookup:(nonnull NSString *)userId;

/**
 * Saves the user profile.
 *
 * @param userProfile The user profile.
 **/
- (void)save:(nonnull NSDictionary *)userProfile;


@end

@interface EOCUserProfileServiceUtility : NSObject
/**
 * Utility method to check if a class conforms to the EOCUserProfileService protocol
 * This method uses compile and run time checks
 */
+ (BOOL)conformsToEOCUserProfileServiceProtocol:(nonnull Class)instanceClass;
@end

/**
 * EOCUserProfileServiceNoOp comforms to the EOCUserProfileService protocol,
 * but all methods perform a no op.
 */
@interface EOCUserProfileServiceNoOp : NSObject <EOCUserProfileService>
@end
