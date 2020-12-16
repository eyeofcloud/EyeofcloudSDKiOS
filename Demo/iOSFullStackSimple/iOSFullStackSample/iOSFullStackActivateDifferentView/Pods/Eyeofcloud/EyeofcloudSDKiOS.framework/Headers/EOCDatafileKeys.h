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

/*
    This class contains all the project datafile JSON keys.
*/

#import <Foundation/Foundation.h>

// ---- Datafile Keys ----
extern NSString * const EOCDatafileKeysAccountId;
extern NSString * const EOCDatafileKeysProjectId;
extern NSString * const EOCDatafileKeysVersion;
extern NSString * const EOCDatafileKeysRevision;
extern NSString * const EOCDatafileKeysAnonymizeIP;
extern NSString * const EOCDatafileKeysExperiments;
extern NSString * const EOCDatafileKeysEvents;
extern NSString * const EOCDatafileKeysAudiences;
extern NSString * const EOCDatafileKeysAttributes;
extern NSString * const EOCDatafileKeysGroups;
extern NSString * const EOCDatafileKeysTrackerURL;
// Experiment
extern NSString * const EOCDatafileKeysExperimentId;
extern NSString * const EOCDatafileKeysExperimentKey;
extern NSString * const EOCDatafileKeysExperimentStatus;
extern NSString * const EOCDatafileKeysExperimentTrafficAllocation;
extern NSString * const EOCDatafileKeysExperimentAudienceIds;
extern NSString * const EOCDatafileKeysExperimentVariations;
extern NSString * const EOCDatafileKeysExperimentForcedVariations;
extern NSString * const EOCDatafileKeysExperimentLayerId;
extern NSString * const EOCDatafileKeysExperimentSticky;
// Events
extern NSString * const EOCDatafileKeysEventExperimentIds;
extern NSString * const EOCDatafileKeysEventId;
extern NSString * const EOCDatafileKeysEventKey;
// Audiences
extern NSString * const EOCDatafileKeysAudienceId;
extern NSString * const EOCDatafileKeysAudienceName;
extern NSString * const EOCDatafileKeysAudienceConditions;
// Attributes
extern NSString * const EOCDatafileKeysAttributeId;
extern NSString * const EOCDatafileKeysAttributeKey;
// Groups
extern NSString * const EOCDatafileKeysGroupPolicy;
extern NSString * const EOCDatafileKeysGroupTrafficAllocation;
extern NSString * const EOCDatafileKeysGroupExperiments;
extern NSString * const EOCDatafileKeysGroupId;
// Traffic Allocation
extern NSString * const EOCDatafileKeysTrafficAllocationEntityId;
extern NSString * const EOCDatafileKeysTrafficAllocationEndOfRange;
// Variations
extern NSString * const EOCDatafileKeysVariationId;
extern NSString * const EOCDatafileKeysVariationKey;
extern NSString * const EOCDatafileKeysVariationVariables;
// Conditions
extern NSString * const EOCDatafileKeysConditionName;
extern NSString * const EOCDatafileKeysConditionType;
extern NSString * const EOCDatafileKeysConditionValue;
extern NSString * const EOCDatafileKeysAndCondition;
extern NSString * const EOCDatafileKeysNotCondition;
extern NSString * const EOCDatafileKeysOrCondition;
// Live Variables
extern NSString * const EOCDatafileKeysVariableId;
extern NSString * const EOCDatafileKeysVariableKey;
extern NSString * const EOCDatafileKeysVariableType;
extern NSString * const EOCDatafileKeysVariableValue;
// Variation Live Variable
extern NSString * const EOCDatafileKeysVariationVariableId;
extern NSString * const EOCDatafileKeysVariationVariableValue;
// User Profile Service (not in datafile yet)
extern NSString * const EOCDatafileKeysUserProfileServiceUserId;
extern NSString * const EOCDatafileKeysUserProfileServiceExperimentBucketMap;
extern NSString * const EOCDatafileKeysUserProfileServiceVariationId;

@interface EOCDatafileKeys : NSObject

@end
