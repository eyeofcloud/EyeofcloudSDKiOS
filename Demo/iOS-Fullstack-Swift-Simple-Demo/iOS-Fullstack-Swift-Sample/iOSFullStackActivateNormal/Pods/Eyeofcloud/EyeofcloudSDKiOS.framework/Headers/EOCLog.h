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
#import <SystemConfiguration/SystemConfiguration.h>

#ifdef LOG_FLAG_ERROR
    #define EOCLogError(args...) eocLog(@"EOCLogError",__FILE__,__LINE__,__PRETTY_FUNCTION__,args);
#else
    #define EOCLogError(args...)
#endif

#ifdef LOG_FLAG_DEBUG
    #define EOCLogDebug(args...) eocLog(@"EOCLogDebug",__FILE__,__LINE__,__PRETTY_FUNCTION__,args);
#else
    #define EOCLogDebug(args...)
#endif

#ifdef LOG_FLAG_INFO
    #define EOCLogInfo(args...) eocLog(@"EOCLogInfo",__FILE__,__LINE__,__PRETTY_FUNCTION__,args);
#else
    #define EOCLogInfo(args...)
#endif

void eocLog(NSString* level, const char* file, int lineNumber, const char* functionName, NSString* format, ...);

@interface EOCLog : NSObject

@end
