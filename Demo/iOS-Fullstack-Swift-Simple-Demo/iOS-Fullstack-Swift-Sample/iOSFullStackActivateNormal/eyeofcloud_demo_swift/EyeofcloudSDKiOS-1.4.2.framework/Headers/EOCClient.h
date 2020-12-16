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
#ifdef UNIVERSAL
    #import "Eyeofcloud.h"
#else
    #import <EyeofcloudSDKCore/Eyeofcloud.h>
#endif
#import "EOCClientBuilder.h"

/**
 * This class wraps the Eyeofcloud class from the Core SDK.
 * Eyeofcloud Client Instance
 */
@interface EOCClient : NSObject <Eyeofcloud>

/// Reference to the Eyeofcloud Core instance
@property (nonatomic, strong, readonly, nullable) Eyeofcloud *eyeofcloud;
/// The Eyeofcloud Core's logger, or if no logger a default logger
@property (nonatomic, strong, readonly, nonnull) id<EOCLogger> logger;
/// Eyeofcloud X Mobile Default Attributes
@property (atomic, strong, readwrite, nullable) NSDictionary *defaultAttributes;

+ (nonnull instancetype)init:(nonnull EOCClientBuilderBlock)builderBlock;

@end
