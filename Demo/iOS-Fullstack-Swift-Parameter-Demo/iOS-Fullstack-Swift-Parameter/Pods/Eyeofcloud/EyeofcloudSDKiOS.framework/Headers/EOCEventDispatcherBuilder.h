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
#ifdef UNIVERSAL
    #import "EyeofcloudSDKShared.h"
    #import "EOCLogger.h"
#else
    #import <EyeofcloudSDKShared/EyeofcloudSDKShared.h>
    #import <EyeofcloudSDKCore/EOCLogger.h>
#endif

/**
 * This class contains details related to how the Eyeofcloud Event Dispatcher instance is built.
 */

@class EOCEventDispatcherBuilder;

/// This is a block that takes the builder values.
typedef void (^EOCEventDispatcherBuilderBlock)(EOCEventDispatcherBuilder * _Nullable builder);

@interface EOCEventDispatcherBuilder : NSObject

/**
* Initializer for Eyeofcloud Event Dispatcher Builder object
*
* @param block The builder block with which to initialize the Eyeofcloud Event Dispatcher Builder object
* @return An instance of EOCEventDispatcherBuilder
*/
+ (nullable instancetype)builderWithBlock:(nonnull EOCEventDispatcherBuilderBlock)block;

/// The interval at which the SDK will attempt to dispatch any events remaining in our events queue
@property (nonatomic, assign, readwrite) NSInteger eventDispatcherDispatchInterval;
/// Max number of events to store before overwriting older events (value must be greater than 1)
@property (nonatomic, assign) NSInteger maxNumberOfEventsToSave;
/// Logger provided by the user
@property (nonatomic, strong, nullable) id<EOCLogger> logger;
/// Event URLs
@property (nonatomic, strong, nullable) NSString *eventDispatcherEventURL;
///
@property (nonatomic, assign, readwrite) BOOL eventDispatcherEventURLHasSetByClientSide;

@end
