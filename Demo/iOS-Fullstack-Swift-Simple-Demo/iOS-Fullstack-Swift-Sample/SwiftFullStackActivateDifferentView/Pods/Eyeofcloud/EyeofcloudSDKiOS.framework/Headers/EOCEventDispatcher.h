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
#import <UIKit/UIKit.h>
#ifdef UNIVERSAL
    #import "EyeofcloudSDKShared.h"
    #import "EyeofcloudSDKCore.h"
    #import "EOCEventDataStore.h"
#else
    #import <EyeofcloudSDKShared/EyeofcloudSDKShared.h>
    #import <EyeofcloudSDKCore/EyeofcloudSDKCore.h>
#endif
#import "EOCEventDispatcherBuilder.h"

/*
 * This class handles the dispatching of the two Eyeofcloud events:
 *   - Impression Event
 *   - Conversion Event
 * The events are dispatched immediately and are only saved if the dispatch fails.
 * The saved events will be dispatched again opportunistically in the following cases:
 *   - Another event dispatch is called
 *   - The app enters the background or foreground
 */

// Default dispatch interval if not set by users
extern NSInteger const EOCEventDispatcherDefaultDispatchIntervalTime_s;
// The max number of events that can be flushed at a time
extern NSInteger const EOCEventDispatcherMaxDispatchEventBatchSize;
// The max number of times flush events are attempted
extern NSInteger const EOCEventDispatcherMaxFlushEventAttempts;
// Default max number of events to store before overwriting older events
extern NSInteger const EOCEventDispatcherDefaultMaxNumberOfEventsToSave;

@protocol EOCEventDispatcher;

typedef void (^EOCEventDispatcherResponse)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error);

@interface EOCEventDispatcherDefault : NSObject <EOCEventDispatcher>

/// The interval at which the SDK will attempt to dispatch any events remaining in our events queue (in ms)
@property (nonatomic, assign, readonly) NSInteger eventDispatcherDispatchInterval;

/// Max number of events to store before overwriting older events (value must be greater than 1)
@property (nonatomic, assign, readonly) NSInteger maxNumberOfEventsToSave;

/// Logger provided by the user
@property (nonatomic, strong, nullable) id<EOCLogger> logger;

/// Event URLs
@property (nonatomic, strong, nullable) NSString *eventDispatcherEventURL;

@property (nonatomic, strong, nullable) NSString *eventConfigDispatcherEventURL;

/**
 * Initializer for Eyeofcloud Event Dispatcher object
 *
 * @param builderBlock The builder block with which to initialize the Eyeofcloud Event Dispatcher object
 * @return An instance of EOCEventDispatcher
 */
+ (nullable instancetype)init:(nonnull EOCEventDispatcherBuilderBlock)builderBlock;

- (nullable instancetype)initWithBuilder:(nullable EOCEventDispatcherBuilder *)builder;


/**
 * Dispatch an impression event.
 * @param params Dictionary of the event parameter values
 * @param callback The completion handler
 */

- (void)dispatchImpressionEvent:(nonnull NSDictionary *)params
                       callback:(nullable EOCEventDispatcherResponse)callback;

/**
 * Dispatch a conversion event.
 * @param params Dictionary of the event parameter values
 * @param callback The completion handler
 */
- (void)dispatchConversionEvent:(nonnull NSDictionary *)params
                       callback:(nullable EOCEventDispatcherResponse)callback;

- (void)setConfigTrackerURL:(nullable NSString *)trackerURL;
/**
 * Flush all events in queue (cached and saved).
 */
-(void)flushEvents;

@end
