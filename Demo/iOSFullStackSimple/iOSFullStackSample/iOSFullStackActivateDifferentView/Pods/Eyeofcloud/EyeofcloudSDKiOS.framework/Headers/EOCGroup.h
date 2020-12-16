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

@protocol EOCExperiment, EOCTrafficAllocation;
/**
 * This class is a representation of an Eyeofcloud Group.
 */

@protocol EOCGroup
@end

@interface EOCGroup : EOCJSONModel

/// The Group's ID.
@property (nonatomic, strong) NSString *groupId;
/// The Group's policy.
@property (nonatomic, strong) NSString *policy;
/// The Group's traffic allocations.
@property (nonatomic, strong) NSArray<EOCTrafficAllocation> *trafficAllocations;
/// The Group's experiments.
@property (nonatomic, strong) NSArray<EOCExperiment> *experiments;

@end
