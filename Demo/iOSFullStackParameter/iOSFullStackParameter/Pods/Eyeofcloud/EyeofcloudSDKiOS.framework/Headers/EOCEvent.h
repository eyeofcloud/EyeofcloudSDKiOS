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

/**
 * This class represents each type of event in the datafile.
 * When the Event builder creates a conversion event, it checks that the event is valid using this class.
 * Each instance is an Eyeofcloud Event Configuration: Revenue goal, custom goal etc.
 */

#import <Foundation/Foundation.h>
#ifdef UNIVERSAL
    #import "EOCJSONModelLib.h"
#else
    #import <EyeofcloudSDKCore/EOCJSONModelLib.h>
#endif

@protocol EOCEvent
@end

@interface EOCEvent : EOCJSONModel

/// an NSString representing the event id
@property (nonatomic, strong) NSString *eventId;
/// an NSString representing a human readable name for the event
@property (nonatomic, strong) NSString *eventKey;
/// An NSArray of experiment ids associated with the event
@property (nonatomic, strong) NSArray *experimentIds;

- (BOOL)containsExperimentId:(NSString *)experimentId;
@end

