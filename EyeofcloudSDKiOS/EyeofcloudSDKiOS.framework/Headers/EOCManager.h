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
    #import "EOCManagerBase.h"
#else
    #import <EyeofcloudSDKShared/EOCManagerBase.h>
#endif

@protocol EOCManager;

@interface EOCManager : EOCManagerBase<EOCManager>
/**
 * Init with builder block
 * @param builderBlock The Eyeofcloud Manager Builder Block where datafile manager, event dispatcher, and other configurations will be set.
 * @return EyeofcloudManager instance
 */
+ (nullable instancetype)init:(nonnull EOCManagerBuilderBlock)builderBlock
__attribute((deprecated("Use OPTLYManager initWithBuilder method instead.")));
- (nullable instancetype)initWithBuilder:(nullable EOCManagerBuilder *)builder;
@end
