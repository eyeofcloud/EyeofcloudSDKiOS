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

@protocol EOCCondition

/**
 * Evaluate the condition against the user attributes.
 */
- (BOOL)evaluateConditionsWithAttributes:(NSDictionary<NSString *, NSString *> *)attributes;

@end

@interface EOCCondition : NSObject

+ (NSArray<EOCCondition> *)deserializeJSONArray:(NSArray *)jsonArray
                                            error:(NSError * __autoreleasing *)error;
+ (NSArray<EOCCondition> *)deserializeJSONArray:(NSArray *)jsonArray;

@end

@interface EOCAndCondition : NSObject <EOCCondition>

@property (nonatomic, strong) NSArray<EOCCondition> *subConditions;

@end

@interface EOCOrCondition : NSObject <EOCCondition>

@property (nonatomic, strong) NSArray<EOCCondition> *subConditions;

@end

@interface EOCNotCondition : NSObject <EOCCondition>

@property (nonatomic, strong) NSObject<EOCCondition> *subCondition;

@end
