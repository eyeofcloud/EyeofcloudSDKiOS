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
    #import "EOCJSONModelLib.h"
#else
    #import <EyeofcloudSDKCore/EOCJSONModelLib.h>
#endif

@class EOCVariation;
@protocol EOCTrafficAllocation, EOCVariation;

/**
 * This class is a representation of an Eyeofcloud Experiment.
 */

@protocol EOCExperiment
@end

NS_ASSUME_NONNULL_BEGIN
extern NSString * const EOCExperimentStatusRunning;
NS_ASSUME_NONNULL_END

@interface EOCExperiment : EOCJSONModel

/// The experiment's ID.
@property (nonatomic, strong, nonnull) NSString *experimentId;
/// The experiment's Key.
@property (nonatomic, strong, nonnull) NSString *experimentKey;
/// The experiment's status.
@property (nonatomic, strong, nonnull) NSString *status;
/// The group ID the experiment belongs to.
@property (nonatomic, strong, nullable) NSString<Ignore> *groupId;
/// The experiment's traffic allocations.
@property (nonatomic, strong, nonnull) NSArray<EOCTrafficAllocation> *trafficAllocations;
/// An array of audience Ids for the experiment
@property (nonatomic, strong, nonnull) NSArray<NSString *> *audienceIds;
/// An array of variation Ids for the experiment
@property (nonatomic, strong, nonnull) NSArray<EOCVariation> *variations;
/// A dictionary indicating the forced and control variation
@property (nonatomic, strong, nonnull) NSDictionary<NSString *, NSString *> *forcedVariations;
/// Personalization layer id
@property (nonatomic, strong, nonnull) NSString *layerId;
@property (nonatomic, strong, nullable) NSNumber<Optional> *sticky;

/// Gets the variation object for a given variation id
- (nullable EOCVariation *)getVariationForVariationId:(nonnull NSString *)variationId;
/// Gets the variation object for a given variation key
- (nullable EOCVariation *)getVariationForVariationKey:(nonnull NSString *)variationKey;

/// Determines if the experiment is running
- (BOOL)isExperimentRunning;

- (BOOL)isExperimentSticky;
@end
