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
    This class contains all the error messages that will be called by the SDK.
    This class does not include the NSException errors that may also be thrown by the OS.
 */

#import <Foundation/Foundation.h>

extern NSString * const EOCErrorHandlerMessagesDomain;

extern NSString * const EOCErrorHandlerMessagesDataFileInvalid;
extern NSString * const EOCErrorHandlerMessagesEventDispatcherInvalid;
extern NSString * const EOCErrorHandlerMessagesLoggerInvalid;
extern NSString * const EOCErrorHandlerMessagesErrorHandlerInvalid;
extern NSString * const EOCErrorHandlerMessagesExperimentUnknown;
extern NSString * const EOCErrorHandlerMessagesEventUnknown;
extern NSString * const EOCErrorHandlerMessagesBuilderInvalid;
extern NSString * const EOCErrorHandlerMessagesEventNoExperimentAssociation;
extern NSString * const EOCErrorHandlerMessagesBucketingIdInvalid;
extern NSString * const EOCErrorHandlerMessagesAttributeUnknown;
extern NSString * const EOCErrorHandlerMessagesAttributeFormatInvalid;
extern NSString * const EOCErrorHandlerMessagesGroupInvalid;
extern NSString * const EOCErrorHandlerMessagesVariationUnknown;
extern NSString * const EOCErrorHandlerMessagesEventTypeUnknown;
extern NSString * const EOCErrorHandlerMessagesUserProfileInvalid;

extern NSString * const EOCErrorHandlerMessagesTrafficAllocationNotInRange;
extern NSString * const EOCErrorHandlerMessagesBucketingIdInvalid;
extern NSString * const EOCErrorHandlerMessagesTrafficAllocationUnknown;
extern NSString * const EOCErrorHandlerMessagesEventDispatchFailed;
extern NSString * const EOCErrorHandlerMessagesConfigInvalid;
extern NSString * const EOCErrorHandlerMessagesLiveVariableKeyUnknown;

extern NSString * const EOCErrorHandlerMessagesManagerBuilderInvalid;

extern NSString *const EOCErrorHandlerMessagesDataStoreDatabaseNoSavedEvents;
extern NSString *const EOCErrorHandlerMessagesDataStoreDatabaseNoDataToSave;
extern NSString *const EOCErrorHandlerMessagesDataStoreInvalidDataStoreEntityValue;
extern NSString *const EOCErrorHandlerMessagesHTTPRequestManagerPOSTRetryFailure;
extern NSString *const EOCErrorHandlerMessagesHTTPRequestManagerGETRetryFailure;
extern NSString *const EOCErrorHandlerMessagesHTTPRequestManagerGETIfModifiedFailure;
extern NSString *const EOCErrorHandlerMessagesProjectConfigInvalidAudienceCondition;


typedef NS_ENUM(NSUInteger, EOCErrorTypes) {
    EOCErrorTypesDatafileInvalid = 0,
    EOCErrorTypesDataUnknown,
    EOCErrorTypesConfigInvalid,
    EOCErrorTypesLoggerInvalid,
    EOCErrorTypesErrorHandlerInvalid,
    EOCErrorTypesBuilderInvalid,
    EOCErrorTypesDatabase,
    EOCErrorTypesDataStore,
    EOCErrorTypesUserProfile,
    EOCErrorTypesEventDispatch,
    EOCErrorTypesEventTrack,
    EOCErrorTypesUserActivate,
    EOCErrorTypesHTTPRequestManager,
};

@interface EOCErrorHandlerMessages : NSObject

@end
