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
#import "EOCLoggerMessages.h"

/**
 * These are the various Eyeofcloud Log Levels.
 * Normally, when messages are logged with priority levels greater than the filter level, they will be suppressed.
 */

typedef NS_ENUM(NSUInteger, EyeofcloudLogLevel) {
    /// If the filter level is set to EyeofcloudLogLevelOff, all log messages will be suppressed.
    EyeofcloudLogLevelOff = 0,
    /// Any error that is causing a crash of the application.
    EyeofcloudLogLevelCritical = 1,
    /// Any error that is not causing a crash of the application: unknown experiment referenced.
    EyeofcloudLogLevelError = 2,
    /// Anything that can potentially cause problems: method will be deprecated.
    EyeofcloudLogLevelWarning = 3,
    /// Useful information: Lifecycle events, successfully activated experiment, parsed datafile.
    EyeofcloudLogLevelInfo= 4,
    /// Information diagnostically helpful: sending events, assigning buckets.
    EyeofcloudLogLevelDebug = 5,
    /// Used for the most granular logging: method flows, variable values.
    EyeofcloudLogLevelVerbose = 6,
    /// If the filter level is set to EyeofcloudLogLevelAll, no log messages will be suppressed.
    EyeofcloudLogLevelAll = 7,
};

NS_ASSUME_NONNULL_BEGIN
extern NSString *const EOCLogLevelCriticalTag;
extern NSString *const EOCLogLevelErrorTag;
extern NSString *const EOCLogLevelWarningTag;
extern NSString *const EOCLogLevelInfoTag;
extern NSString *const EOCLogLevelDebugTag;
extern NSString *const EOCLogLevelVerboseTag;
NS_ASSUME_NONNULL_END

/**
 * Any logger must implement these following methods.
 */
@protocol EOCLogger <NSObject>

/// The log level the Logger is initialized with.
@property (readonly) EyeofcloudLogLevel logLevel;

/**
 * Initialize a new Eyeofcloud Logger instance.
 */
- (nullable instancetype)initWithLogLevel:(EyeofcloudLogLevel)logLevel;

/**
 Log a message at a certain level.
 @param message The message to log.
 @param level The priority level of the log.
 */
- (void)logMessage:(nonnull NSString *)message withLevel:(EyeofcloudLogLevel)level;

@end

@interface EOCLoggerUtility : NSObject
/**
 * Utility method to check if a class conforms to the EOCLogger protocol
 * This method uses compile and run time checks
 */
+ (BOOL)conformsToEOCLoggerProtocol:(nonnull Class)instanceClass;
@end

/**
 * Default logger that logs info level values.
 */
@interface EOCLoggerDefault : NSObject <EOCLogger>

/// The log you initialize the logger with.
@property (readonly) EyeofcloudLogLevel logLevel;

@end
