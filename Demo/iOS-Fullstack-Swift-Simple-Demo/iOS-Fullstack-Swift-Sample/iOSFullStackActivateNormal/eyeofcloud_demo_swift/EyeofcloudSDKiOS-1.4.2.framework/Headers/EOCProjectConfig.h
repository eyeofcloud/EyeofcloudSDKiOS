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
#import "EOCProjectConfigBuilder.h"

NS_ASSUME_NONNULL_BEGIN
extern NSString * const kExpectedDatafileVersion;
NS_ASSUME_NONNULL_END

@class EOCAttribute, EOCAudience, EOCBucketer, EOCEvent, EOCExperiment, EOCGroup, EOCUserProfileService, EOCVariation, EOCVariable;
@protocol EOCAttribute, EOCAudience, EOCBucketer, EOCErrorHandler, EOCEvent, EOCExperiment, EOCGroup, EOCLogger, EOCVariable, EOCVariation;

/*
    This class represents all the data contained in the project datafile 
    and includes helper methods to efficiently access its data.
 */

@interface EOCProjectConfig : EOCJSONModel

/// Account Id
@property (nonatomic, strong, nonnull) NSString *accountId;
/// Project Id
@property (nonatomic, strong, nonnull) NSString *projectId;
/// JSON Version
@property (nonatomic, strong, nonnull) NSString *version;
/// Datafile Revision number
@property (nonatomic, strong, nonnull) NSString *revision;
/// Flag for IP anonymization
@property (nonatomic, assign) BOOL anonymizeIP;
/// List of Eyeofcloud Experiment objects
@property (nonatomic, strong, nonnull) NSArray<EOCExperiment> *experiments;
/// List of Eyeofcloud Event Type objects
@property (nonatomic, strong, nonnull) NSArray<EOCEvent> *events;
/// List of audience ids
@property (nonatomic, strong, nonnull) NSArray<EOCAudience> *audiences;
/// List of attributes objects
@property (nonatomic, strong, nonnull) NSArray<EOCAttribute> *attributes;
/// List of group objects
@property (nonatomic, strong, nonnull) NSArray<EOCGroup> *groups;
/// List of live variable objects
/// TODO: Make variables required
@property (nonatomic, strong, nonnull) NSArray<EOCVariable, Optional> *variables;

/// a comprehensive list of experiments that includes experiments being whitelisted (in Groups)
@property (nonatomic, strong, nullable) NSArray<EOCExperiment, Ignore> *allExperiments;
@property (nonatomic, strong, nullable) id<EOCLogger, Ignore> logger;
@property (nonatomic, strong, nullable) id<EOCErrorHandler, Ignore> errorHandler;
@property (nonatomic, strong, readonly, nullable) id<EOCUserProfileService, Ignore> userProfileService;

/// Returns the client type (e.g., objective-c-sdk, ios-sdk, tvos-sdk)
@property (nonatomic, strong, readonly, nonnull) NSString<Ignore> *clientEngine;
/// Returns the client version number
@property (nonatomic, strong, readonly, nonnull) NSString<Ignore> *clientVersion;

/**
 * Initialize the Project Config from a builder block.
 */
+ (nullable instancetype)init:(nonnull EOCProjectConfigBuilderBlock)builderBlock;

/**
 * Initialize the Project Config from a datafile.
 */
- (nullable instancetype)initWithDatafile:(nonnull NSData *)datafile;

/**
 * Get an Experiment object for a key.
 */
- (nullable EOCExperiment *)getExperimentForKey:(nonnull NSString *)experimentKey;

/**
 * Get an Experiment object for an Id.
 */
- (nullable EOCExperiment *)getExperimentForId:(nonnull NSString *)experimentId;

/**
* Get an experiment Id for the human readable experiment key
**/
- (nullable NSString *)getExperimentIdForKey:(nonnull NSString *)experimentKey;

/**
 * Get a Group object for an Id.
 */
- (nullable EOCGroup *)getGroupForGroupId:(nonnull NSString *)groupId;

/**
 * Gets an event id for a corresponding event key
 */
- (nullable NSString *)getEventIdForKey:(nonnull NSString *)eventKey;

/**
 * Gets an event for a corresponding event key
 */
- (nullable EOCEvent *)getEventForKey:(nonnull NSString *)eventKey;

/**
* Get an attribute for a given key.
*/
- (nullable EOCAttribute *)getAttributeForKey:(nonnull NSString *)attributeKey;

/**
 * Get an audience for a given audience id.
 */
- (nullable EOCAudience *)getAudienceForId:(nonnull NSString *)audienceId;

/**
 * Get a variable for a given live variable key.
 */
- (nullable EOCVariable *)getVariableForVariableKey:(nonnull NSString *)variableKey;

/**
 * Get forced variation for a given experiment key and user id.
 */
- (nullable EOCVariation *)getForcedVariation:(nonnull NSString *)experimentKey
                                         userId:(nonnull NSString *)userId;

/**
 * Set forced variation for a given experiment key and user id according to a given variation key.
 */
- (BOOL)setForcedVariation:(nonnull NSString *)experimentKey
                    userId:(nonnull NSString *)userId
              variationKey:(nonnull NSString *)variationKey;

/**
 * Get variation for experiment and user ID with user attributes.
 */
- (nullable EOCVariation *)getVariationForExperiment:(nonnull NSString *)experimentKey
                                                userId:(nonnull NSString *)userId
                                            attributes:(nullable NSDictionary<NSString *,NSString *> *)attributes
                                              bucketer:(nullable id<EOCBucketer>)bucketer;

@end
