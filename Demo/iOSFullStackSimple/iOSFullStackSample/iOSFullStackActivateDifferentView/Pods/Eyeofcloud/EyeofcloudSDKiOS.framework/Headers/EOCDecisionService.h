/****************************************************************************
 * Copyright 2017, Eyeofcloud, Inc. and contributors                        *
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

#ifdef UNIVERSAL
    #import "EOCJSONModelLib.h"
#else
    #import <EyeofcloudSDKCore/EOCJSONModelLib.h>
#endif

// An optional bucketing ID may be provided in attributes via a
// key-value pair
//     EyeofcloudBucketId : bucketId
// to accomplish decoupling bucketing from user identification so
// that a group of users that have the same bucketing ID are put
// into the same variation.
// A Bucketing ID allows equivalence relation on user IDs. A group
// of users with the same bucketing ID defines an equivalence class
// of user IDs that all map to the same experiment variation.
extern NSString * _Nonnull const EyeofcloudBucketId;

@class EOCExperiment, EOCVariation;

@interface EOCDecisionService : EOCJSONModel

/**
 * Initializer for the Decision Service.
 *
 * @param config The project configuration.
 * @param bucketer The bucketer.
 * @return An instance of the decision service.
 */
- (nullable instancetype)initWithProjectConfig:(nonnull EOCProjectConfig *)config
                                      bucketer:(nonnull id<EOCBucketer>)bucketer;

/**
 * Gets a variation based on the following rules (evaluated in sequential order):
 *
 * 1. Experiments not running will return a nil variation.
 * 2. If the user is whitelisted for a particular variation, 
 *    then that variation will be returned.
 * 3. If a valid variation for a given experiments is found in the user
 *    profile service, then that variation will be returned.
 * 4. If the user falls through #1-3, than the user will be bucketed
 *    if the user fulfills these criteria:
 *      a. Does the user pass audience targeting?
 *      b. Is the experiment that the user bucketed into NOT mutually excluded?
 *      c. Does traffic allocation exclude the user?
 *
 * @param userId The ID of the user.
 * @param experiment The experiment in which to bucket the user.
 * @return The variation assigned to the specified user ID for an experiment.
 */
- (nullable EOCVariation *)getVariation:(nonnull NSString *)userId
                               experiment:(nonnull EOCExperiment *)experiment
                               attributes:(nullable NSDictionary *)attributes;
    
@end
