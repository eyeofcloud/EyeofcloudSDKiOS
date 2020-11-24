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

#import "Eyeofcloud.h"
#import "EOCAttribute.h"
#import "EOCAudience.h"
#import "EOCBaseCondition.h"
#import "EOCBucketer.h"
#import "EOCBuilder.h"
#import "EOCCondition.h"
#import "EOCDatafileKeys.h"
#import "EOCDecisionService.h"
#import "EOCDecisionEventTicket.h"
#import "EOCErrorHandler.h"
#import "EOCErrorHandlerMessages.h"
#import "EOCEvent.h"
#import "EOCEventAudience.h"
#import "EOCEventBuilder.h"
#import "EOCEventDecision.h"
#import "EOCEventDecisionTicket.h"
#import "EOCEventDispatcherBasic.h"
#import "EOCEventFeature.h"
#import "EOCEventHeader.h"
#import "EOCEventLayerState.h"
#import "EOCEventMetric.h"
#import "EOCEventParameterKeys.h"
#import "EOCEventRelatedEvent.h"
#import "EOCEventTicket.h"
#import "EOCEventView.h"
#import "EOCExperiment.h"
#import "EOCExperimentBucketMapEntity.h"
#import "EOCGroup.h"
#import "EOCHTTPRequestManager.h"
#import "EOCLog.h"
#import "EOCLogger.h"
#import "EOCLoggerMessages.h"
#import "EOCNetworkService.h"
#import "EOCProjectConfig.h"
#import "EOCProjectConfigBuilder.h"
#import "EOCQueue.h"
#import "EOCTrafficAllocation.h"
#import "EOCUserProfile.h"
#import "EOCUserProfileServiceBasic.h"
#import "EOCVariable.h"
#import "EOCVariation.h"
#import "EOCVariationVariable.h"

#import "EOCJSONModel.h"
#import "EOCJSONModelClassProperty.h"
#import "EOCJSONModelError.h"
#import "EOCJSONModelLib.h"
#import "EOCJSONKeyMapper.h"
#import "EOCJSONValueTransformer.h"

FOUNDATION_EXPORT double EyeofcloudSDKCoreVersionNumber;
FOUNDATION_EXPORT const unsigned char EyeofcloudSDKCoreVersionString[];
