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


@protocol EOCAttribute
@end

@interface EOCAttribute : EOCJSONModel

/// The attribute id
@property (nonatomic, strong) NSString *attributeId;
/// The attribute key (name)
@property (nonatomic, strong) NSString *attributeKey;

@end
