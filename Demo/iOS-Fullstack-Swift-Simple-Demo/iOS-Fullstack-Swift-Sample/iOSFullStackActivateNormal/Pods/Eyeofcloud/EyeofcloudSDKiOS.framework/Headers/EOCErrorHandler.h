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
#import "EOCErrorHandlerMessages.h"

/**
 * This class determines how the Eyeofcloud SDK will handle exceptions and errors.
 */
@protocol EOCErrorHandler <NSObject>

/**
 * Handle an error thrown by the SDK.
 * @param error The error object to be handled.
 */
- (void)handleError:(NSError *)error;

/**
 * Handle an exception thrown by the SDK.
 * @param exception The exception object to be handled.
 */
- (void)handleException:(NSException *)exception;

@end

@interface EOCErrorHandler : NSObject
/**
 * Utility method to check if a class conforms to the EOCErrorHandler protocol
 * This method uses compile and run time checks
 */
+ (BOOL)conformsToEOCErrorHandlerProtocol:(Class)instanceClass;

/**
 * Utility method to package Apple-specific errors which then calls the error handler.
 */
+ (void)handleError:(id<EOCErrorHandler>) errorHandler
               code:(NSInteger)code
        description:(NSString *)localizedDescription;
@end

@interface EOCErrorHandlerDefault : NSObject <EOCErrorHandler>
@end

/**
 * EOCErrorHandlerNoOp comforms to the EOCErrorHandler protocol,
 * but all methods perform a no op.
 */
@interface EOCErrorHandlerNoOp : NSObject <EOCErrorHandler>
@end
