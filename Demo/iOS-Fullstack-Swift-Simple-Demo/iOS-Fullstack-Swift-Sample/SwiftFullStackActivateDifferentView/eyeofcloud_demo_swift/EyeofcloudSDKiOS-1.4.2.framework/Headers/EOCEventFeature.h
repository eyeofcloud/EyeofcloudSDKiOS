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

// Model object to represent a feature (i.e. tag) that can be applied to a user, page, or event

#import <Foundation/Foundation.h>
#ifdef UNIVERSAL
    #import "EOCJSONModelLib.h"
#else
    #import <EyeofcloudSDKCore/EOCJSONModelLib.h>
#endif

NS_ASSUME_NONNULL_BEGIN
extern NSString * const EOCEventFeatureFeatureTypeCustomAttribute;
NS_ASSUME_NONNULL_END

@protocol EOCEventFeature
@end

@interface EOCEventFeature : EOCJSONModel

// The ID of feature for non-custom features. Should be the GAE ID if it exists.
@property (nonatomic, strong, nullable) NSString<Optional> *featureId;
// The name of the feature, which along with type uniquely identify the feature.
@property (nonatomic, strong, nullable) NSString<Optional> *name;
// The type the feature, which along with name uniquely identifies the feature.
@property (nonatomic, strong, nullable) NSString<Optional> *type;
// The value of the feature (supports: string, long, int, double, float, boolean)
@property (nonatomic, strong, nonnull) id value;
// If true, this feature will be indexed in the counting service. Otherwise it will just be logged
@property (nonatomic, assign) BOOL shouldIndex;

@end
