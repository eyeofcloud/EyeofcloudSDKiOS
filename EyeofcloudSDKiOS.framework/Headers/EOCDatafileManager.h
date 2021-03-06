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
    #import "EOCDatafileManager.h"
#else
    #import <EyeofcloudSDKShared/EOCDatafileManagerBasic.h>
#endif
#import "EOCDatafileManagerBuilder.h"

@protocol EOCDatafileManager, EOCErrorHandler, EOCLogger;

@interface EOCDatafileManagerDefault : NSObject<EOCDatafileManager>

/// The time interval to regularly fetch the datafile.
@property (nonatomic, readonly) NSTimeInterval datafileFetchInterval;
/// This flag specifies if the datafile has been cached or not.
@property (nonatomic, assign) BOOL isDatafileCached;
/// The project ID of the datafile this datafile manager will monitor
@property (nonatomic, readonly, strong, nonnull) NSString *projectId;
/// The error handler to be used for the manager, client, and all subcomponents
@property (nonatomic, readonly, strong, nullable) id<EOCErrorHandler> errorHandler;
/// A logger for the EOCDatafileManager to log messages.
@property (nonatomic, readonly, strong, nonnull) id<EOCLogger> logger;
/// Datafile Download URLs
@property (nonatomic, strong, nullable) NSString *networkServiceCDNServerURL;

/**
 * Init with builder block
 * @param builderBlock The builder block containing the datafile fetch interval.
 * @return an Eyeofcloud Datafile Manager instance.
 */
+ (nullable instancetype)init:(nonnull EOCDatafileManagerBuilderBlock)builderBlock;

- (nullable instancetype)initWithBuilder:(nullable EOCDatafileManagerBuilder *)builder;


@end
