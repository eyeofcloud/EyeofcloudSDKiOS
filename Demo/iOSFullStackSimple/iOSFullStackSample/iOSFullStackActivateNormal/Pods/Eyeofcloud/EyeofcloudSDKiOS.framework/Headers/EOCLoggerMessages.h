/****************************************************************************
 * Copyright 2016-2017, Eyeofcloud, Inc. and contributors                   *
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
 This class contains all the log messages that will be called by the SDK.
 */

#import <Foundation/Foundation.h>

// ---- Eyeofcloud ----
// debug
extern NSString *const EOCLoggerMessagesVariationUserAssigned;
// info
extern NSString *const EOCLoggerMessagesActivationSuccess;
extern NSString *const EOCLoggerMessagesConversionSuccess;

// ---- Bucketer ----
// debug
extern NSString *const EOCLoggerMessagesBucketAssigned;
// info
extern NSString *const EOCLoggerMessagesForcedVariationUser;
extern NSString *const EOCLoggerMessagesUserMutuallyExcluded;
// error
extern NSString *const EOCLoggerMessagesForcedBucketingFailed;

// ---- Client ----
// error
extern NSString *const EOCLoggerMessagesActivationFailure;
extern NSString *const EOCLoggerMessagesClientDummyEyeofcloudError;
extern NSString *const EOCLoggerMessagesGetVariationFailure;
extern NSString *const EOCLoggerMessagesTrackFailure;

// ---- Data Store ----
// Event Data Store
// debug
extern NSString *const EOCLoggerMessagesDataStoreDatabaseEventDataStoreError;
extern NSString *const EOCLoggerMessagesDataStoreDatabaseSaveError;
extern NSString *const EOCLoggerMessagesDataStoreDatabaseGetError;
extern NSString *const EOCLoggerMessagesDataStoreDatabaseGetNumberEvents;
extern NSString *const EOCLoggerMessagesDataStoreDatabaseRemoveError;
extern NSString *const EOCLoggerMessagesDataStoreDatabaseRemoveEventError;
// warning
extern NSString *const EOCLoggerMessagesDataStoreEventsRemoveAllWarning;
extern NSString *const EOCLoggerMessagesDataStoreDatabaseGetNoEvents;
extern NSString *const EOCLoggerMessagesDataStoreDatabaseRemovingOldEvents;

// File Manager
// debug
extern NSString *const EOCLoggerMessagesDataStoreFileManagerGetFile;
extern NSString *const EOCLoggerMessagesDataStoreFileManagerRemoveAllFilesError;
extern NSString *const EOCLoggerMessagesDataStoreFileManagerRemoveFileForDataTypeError;
extern NSString *const EOCLoggerMessagesDataStoreFileManagerRemoveFilesForDataTypeError;
extern NSString *const EOCLoggerMessagesDataStoreFileManagerSaveFile;

// ---- Datafile Manager ----
// debug
extern NSString *const EOCLoggerMessagesDatafileManagerDatafileNotDownloadedInvalidStatusCode;
extern NSString *const EOCLoggerMessagesDatafileManagerDatafileNotDownloadedError;
extern NSString *const EOCLoggerMessagesDatafileManagerDatafileNotDownloadedNoChanges;
extern NSString *const EOCLoggerMessagesDatafileManagerLastModifiedDate;
extern NSString *const EOCLoggerMessagesDatafileManagerLastModifiedDateFound;
extern NSString *const EOCLoggerMessagesDatafileManagerLastModifiedDateNotFound;
// info
extern NSString *const EOCLoggerMessagesDatafileManagerDatafileDownloaded;
extern NSString *const EOCLoggerMessagesDatafileManagerDatafileDownloading;
extern NSString *const EOCLoggerMessagesDatafileManagerDatafileSaved;

// Datafile Manager Builder
// warning
extern NSString *const EOCLoggerMessagesDatafileManagerInitializedWithoutProjectIdMessage;
// error
extern NSString *const EOCLoggerMessagesDatafileFetchIntervalInvalid;
// error
extern NSString *const EOCLoggerMessagesDatafileURLInvalid;
// error
extern NSString *const EOCLoggerMessagesDefaultDatafileFetchInterval;
// error
extern NSString *const EOCLoggerMessagesMinimumDatafileFetchInterval;


// ---- Datafile Versioning ----
// warning
extern NSString *const EOCLoggerMessagesInvalidDatafileVersion;

// ---- Event Builder ----
// debug
extern NSString *const EOCLoggerMessagesAttributeInvalidFormat;
extern NSString *const EOCLoggerMessagesAttributeValueInvalidFormat;
extern NSString *const EOCLoggerMessagesEventNotAssociatedWithExperiment;
extern NSString *const EOCLoggerMessagesExperimentNotPartOfEvent;
// warning
extern NSString *const EOCLoggerMessagesBucketerInvalid;
extern NSString *const EOCLoggerMessagesEventKeyInvalid;
extern NSString *const EOCLoggerMessagesExperimentKeyInvalid;
extern NSString *const EOCLoggerMessagesNotBuildingDecisionEventTicket;
extern NSString *const EOCLoggerMessagesUserIdInvalid;
extern NSString *const EOCLoggerMessagesVariationIdInvalid;
extern NSString *const EOCLoggerMessagesEventNotPassAudienceEvaluation;
extern NSString *const EOCLoggerMessagesRevenueValueFloat;
extern NSString *const EOCLoggerMessagesRevenueValueString;
extern NSString *const EOCLoggerMessagesRevenueValueIntegerOverflow;
extern NSString *const EOCLoggerMessagesRevenueValueFloatOverflow;
extern NSString *const EOCLoggerMessagesRevenueValueInvalidBoolean;
extern NSString *const EOCLoggerMessagesRevenueValueInvalid;
extern NSString *const EOCLoggerMessagesNumericValueString;
extern NSString *const EOCLoggerMessagesNumericValueInvalidBoolean;
extern NSString *const EOCLoggerMessagesNumericValueInvalidFloat;
extern NSString *const EOCLoggerMessagesNumericValueInvalidString;
extern NSString *const EOCLoggerMessagesNumericValueInvalid;
extern NSString *const EOCLoggerMessagesEventTagValueInvalid;

// ---- Event Dispatcher ----
// info
extern NSString *const EOCLoggerMessagesEventDispatcherAttemptingToSendConversionEvent;
extern NSString *const EOCLoggerMessagesEventDispatcherAttemptingToSendImpressionEvent;
extern NSString *const EOCLoggerMessagesEventDispatcherTrackingSuccess;
extern NSString *const EOCLoggerMessagesEventDispatcherActivationSuccess;
// warning
extern NSString *const EOCLoggerMessagesEventDispatcherInvalidInterval;

// debug
extern NSString *const EOCLoggerMessagesEventDispatcherProperties;
extern NSString *const EOCLoggerMessagesEventDispatcherNetworkTimerEnabled;
extern NSString *const EOCLoggerMessagesEventDispatcherNetworkTimerDisabled;
extern NSString *const EOCLoggerMessagesEventDispatcherFlushingEvents;
extern NSString *const EOCLoggerMessagesEventDispatcherFlushEventsNoEvents;
extern NSString *const EOCLoggerMessagesEventDispatcherFlushEventsMax;
extern NSString *const EOCLoggerMessagesEventDispatcherFlushingSavedEvents;
extern NSString *const EOCLoggerMessagesEventDispatcherFlushSavedEventsNoEvents;
extern NSString *const EOCLoggerMessagesEventDispatcherDispatchFailed;
extern NSString *const EOCLoggerMessagesEventDispatcherPendingEvent;
extern NSString *const EOCLoggerMessagesEventDispatcherEventSaved;
extern NSString *const EOCLoggerMessagesEventDispatcherRemovedEvent;
extern NSString *const EOCLoggerMessagesEventDispatcherInvalidEvent;

// error
extern NSString *const EOCLoggerMessagesEventDispatcherEventNotTracked;
extern NSString *const EOCLoggerMessagesEventDispatcherActivationFailure;
extern NSString *const EOCLoggerMessagesEventDispatcherEventURLInvalid;

// ---- Live Variables ----
// info
extern NSString *const EOCLoggerMessagesVariableValue;
extern NSString *const EOCLoggerMessagesNoVariationFoundForExperimentWithLiveVariable;
// warning
extern NSString *const EOCLoggerMessagesNoExperimentsContainVariable;
extern NSString *const EOCLoggerMessagesVariableUnknownForVariableKey;

// ---- Manager ----
// error
extern NSString *const EOCLoggerMessagesManagerBuilderNotValid;
extern NSString *const EOCLoggerMessagesManagerDatafileManagerDoesNotConformToEOCDatafileManagerProtocol;
extern NSString *const EOCLoggerMessagesManagerErrorHandlerDoesNotConformToEOCErrorHandlerProtocol;
extern NSString *const EOCLoggerMessagesManagerEventDispatcherDoesNotConformToEOCEventDispatcherProtocol;
extern NSString *const EOCLoggerMessagesManagerLoggerDoesNotConformToEOCLoggerProtocol;
extern NSString *const EOCLoggerMessagesManagerMustBeInitializedWithProjectId;
extern NSString *const EOCLoggerMessagesManagerProjectIdCannotBeEmptyString;

// ---- Project Config Getters ----
// debug
extern NSString *const EOCLoggerMessagesAttributeUnknownForAttributeKey;
extern NSString *const EOCLoggerMessagesAudienceUnknownForAudienceId;
extern NSString *const EOCLoggerMessagesEventIdUnknownForEventKey;
extern NSString *const EOCLoggerMessagesEventUnknownForEventKey;
extern NSString *const EOCLoggerMessagesExperimentIdUnknownForExperimentKey;
extern NSString *const EOCLoggerMessagesExperimentUnknownForExperimentId;
extern NSString *const EOCLoggerMessagesExperimentUnknownForExperimentKey;
extern NSString *const EOCLoggerMessagesGroupUnknownForGroupId;
extern NSString *const EOCLoggerMessagesGetVariationNilVariation;
extern NSString *const EOCLoggerMessagesVariationKeyUnknownForExperimentKey;
extern NSString *const EOCLoggerMessagesProjectConfigUserIdInvalid;

// ---- User Profile ----
// debug
extern NSString *const EOCLoggerMessagesUserProfileBucketerUserDataRetrieved;
extern NSString *const EOCLoggerMessagesUserProfileAttemptToSaveVariation;
extern NSString *const EOCLoggerMessagesUserProfileNoVariation;
extern NSString *const EOCLoggerMessagesUserProfileRemoveVariation;
extern NSString *const EOCLoggerMessagesUserProfileRemoveVariationNotFound;
extern NSString *const EOCLoggerMessagesUserProfileServiceSaved;
extern NSString *const EOCLoggerMessagesUserProfileVariation;
extern NSString *const EOCLoggerMessagesUserProfileNotExist;
// warning
extern NSString *const EOCLoggerMessagesUserProfileUnableToSaveVariation;
extern NSString *const EOCLoggerMessagesUserProfileVariationNoLongerInDatafile;
extern NSString *const EOCLoggerMessagesUserProfileSaveInvalidUserId;
extern NSString *const EOCLoggerMessagesUserProfileLookupInvalidFormat;
extern NSString *const EOCLoggerMessagesUserProfileSaveInvalidFormat;

// ---- Decision Service ----
extern NSString *const EOCLoggerMessagesDecisionServiceExperimentNotRunning;
extern NSString *const EOCLoggerMessagesDecisionServiceFailAudienceTargeting;
extern NSString *const EOCLoggerMessagesDecisionServiceSavedVariationInvalid;
extern NSString *const EOCLoggerMessagesDecisionServiceUserProfileNotExist;
extern NSString *const EOCLoggerMessagesDecisionServiceSavedVariationParseError;
extern NSString *const EOCLoggerMessagesDecisionServiceGetVariationParseError;
extern NSString *const EOCLoggerMessagesDecisionServiceReplaceBucketEntity;
extern NSString *const EOCLoggerMessagesDecisionServiceSettingTheBucketingID;

// ---- HTTP Request Manager ----
// Debug (not through logger handler)
extern NSString *const EOCHTTPRequestManagerGETWithParametersAttempt;
extern NSString *const EOCHTTPRequestManagerGETIfModifiedSince;
extern NSString *const EOCHTTPRequestManagerPOSTWithParameters;
extern NSString *const EOCHTTPRequestManagerBackoffRetryStates;

@interface EOCLoggerMessages : NSObject

@end
