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

@class EOCProjectConfig;

@protocol EOCEventDispatcher <NSObject>

/**
 * Dispatch an impression event.
 * @param params Dictionary of the event parameter values
 * @param callback The completion handler
 */

- (void)dispatchImpressionEvent:(nonnull NSDictionary *)params
                       callback:(nullable void(^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))callback;

/**
 * Dispatch a conversion event.
 * @param params Dictionary of the event parameter values
 * @param callback The completion handler
 */
- (void)dispatchConversionEvent:(nonnull NSDictionary *)params
                       callback:(nullable void(^)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))callback;

- (void)setConfigTrackerURL:(nullable NSString *)trackerURL;
@end

@interface EOCEventDispatcherUtility : NSObject
/**
 * Utility method to check if a class conforms to the EOCEventDispatcher protocol
 * This method uses compile and run time checks
 */
+ (BOOL)conformsToEOCEventDispatcherProtocol:(nonnull Class)instanceClass;
@end

/**
 * EOCEventDispatcherBasic is a very simple implementation of the EOCEventDispatcher protocol.
 * It dispatches events without any failure mechanisms (e.g., events are not queued up for a loater 
 * retry.
 */
@interface EOCEventDispatcherBasic : NSObject <EOCEventDispatcher>
@end

/**
 * EOCEventDispatcherNoOp comforms to the EOCEventDispatcher protocol,
 * but all methods perform a no op.
 */
@interface EOCEventDispatcherNoOp : NSObject<EOCEventDispatcher>
@end
