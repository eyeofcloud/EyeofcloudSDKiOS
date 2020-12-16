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

NS_ASSUME_NONNULL_BEGIN
// --- Common Event Parameters ----
extern NSString * const EOCEventParameterKeysTimestamp;
extern NSString * const EOCEventParameterKeysRevision;
extern NSString * const EOCEventParameterKeysActivationId;
extern NSString * const EOCEventParameterKeysSessionId;
extern NSString * const EOCEventParameterKeysVisitorId;
extern NSString * const EOCEventParameterKeysVisitorUUID;
extern NSString * const EOCEventParameterKeysProjectId;
extern NSString * const EOCEventParameterKeysAccountId;
extern NSString * const EOCEventParameterKeysClientEngine;
extern NSString * const EOCEventParameterKeysClientVersion;
extern NSString * const EOCEventParameterKeysHeader;
extern NSString * const EOCEventParameterKeysUserFeatures;
extern NSString * const EOCEventParameterKeysIsGlobalHoldback;
extern NSString * const EOCEventParameterKeysAnonymizeIP;

// --- Decision Ticket Event Parameters ("Impression Event") ----
extern NSString * const EOCEventParameterKeysDecisionId;
extern NSString * const EOCEventParameterKeysLayerId;
extern NSString * const EOCEventParameterKeysDecisionTicket;
extern NSString * const EOCEventParameterKeysDecision;

// --- Event Ticket Parameters ("Conversion Event") ----
extern NSString * const EOCEventParameterKeysEventId;
extern NSString * const EOCEventParameterKeysEventEntityId;
extern NSString * const EOCEventParameterKeysEventType;
extern NSString * const EOCEventParameterKeysEventName;
extern NSString * const EOCEventParameterKeysEventFeatures;
extern NSString * const EOCEventParameterKeysEventMetrics;
extern NSString * const EOCEventParameterKeysRelatedEvents;
extern NSString * const EOCEventParameterKeysLayerStates;
extern NSString * const EOCEventParameterKeysActiveViews;

// ---- Header Parameters ----
extern NSString * const EOCEventParameterKeysHeaderClientIp;
extern NSString * const EOCEventParameterKeysHeaderUserAgent;
extern NSString * const EOCEventParameterKeysHeaderReferer;

// ---- Feature Parameters ----
extern NSString * const EOCEventParameterKeysFeaturesId;
extern NSString * const EOCEventParameterKeysFeaturesName;
extern NSString * const EOCEventParameterKeysFeaturesType;
extern NSString * const EOCEventParameterKeysFeaturesValue;
extern NSString * const EOCEventParameterKeysFeaturesShouldIndex;

// ---- Metric Parameters ----
extern NSString * const EOCEventParameterKeysMetricName;
extern NSString * const EOCEventParameterKeysMetricValue;

// ---- Related Event Parameters ----
extern NSString * const EOCEventParameterKeysRelatedEventsEventId;
extern NSString * const EOCEventParameterKeysRelatedEventsRelationship;

// ---- Audience Parameters ----
extern NSString * const EOCEventParameterKeysAudienceId;
extern NSString * const EOCEventParameterKeysAudienceName;

// ---- Decision Ticket Parameters ----
extern NSString * const EOCEventParameterKeysDecisionTicketAudiences;
extern NSString * const EOCEventParameterKeysDecisionTicketBucketingId;

// ---- Decision Parameters ----
extern NSString * const EOCEventParameterKeysDecisionExperimentId;
extern NSString * const EOCEventParameterKeysDecisionVariationId;
extern NSString * const EOCEventParameterKeysDecisionIsLayerHoldback;

// ---- Layer State Parameters ----
extern NSString * const EOCEventParameterKeysLayerStateLayerId;
extern NSString * const EOCEventParameterKeysLayerStateDecisionTicket;
extern NSString * const EOCEventParameterKeysLayerStateDecision;
extern NSString * const EOCEventParameterKeysLayerStateActivationId;
extern NSString * const EOCEventParameterKeysLayerStateDecisionSessionId;
extern NSString * const EOCEventParameterKeysLayerStateDecisionTimestamp;
extern NSString * const EOCEventParameterKeysLayerStateDecisionEventId;
extern NSString * const EOCEventParameterKeysLayerStateActionTriggered;
extern NSString * const EOCEventParameterKeysLayerStateActionActivationId;
extern NSString * const EOCEventParameterKeysLayerStateActionSessionId;
extern NSString * const EOCEventParameterKeysLayerStateActionTimestamp;
extern NSString * const EOCEventParameterKeysLayerStateRevision;

// ----View Parameters ----
extern NSString * const EOCEventParameterKeysViewViewId;
extern NSString * const EOCEventParameterKeysViewViewActivatedTimestamp;
extern NSString * const EOCEventParameterKeysViewViewFeatures;

// ----Required Parameters ----
extern NSString * const EOCEventParameterKeysSiteId;
extern NSString * const EOCEventParameterKeysGoalId;
extern NSString * const EOCEventParameterKeysRec;
extern NSString * const EOCEventParameterKeysUrl;

// ----Recommended Parameters ----
extern NSString * const EOCEventParameterKeysUniqueVisitorId;
extern NSString * const EOCEventParameterKeysVisitorId;
extern NSString * const EOCEventParameterKeysUserId;
extern NSString * const EOCEventParameterKeysActionName;
extern NSString * const EOCEventParameterKeysActivedVariationIds;
extern NSString * const EOCEventParameterKeysCurrentHour;
extern NSString * const EOCEventParameterKeysCurrentMinute;
extern NSString * const EOCEventParameterKeysCurrentSecond;

extern NS_ASSUME_NONNULL_END

@interface EOCEventParameterKeys : NSObject

@end
