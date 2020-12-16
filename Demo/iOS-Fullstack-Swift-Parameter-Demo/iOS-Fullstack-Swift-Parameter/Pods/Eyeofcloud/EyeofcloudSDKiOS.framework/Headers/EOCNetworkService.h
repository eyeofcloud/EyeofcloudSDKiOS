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

#import <Foundation/Foundation.h>
#import "EOCHTTPRequestManager.h"

NS_ASSUME_NONNULL_BEGIN
extern const NSInteger EOCNetworkServiceEventDispatchMaxBackoffRetryAttempts;
extern const NSInteger EOCNetworkServiceEventDispatchMaxBackoffRetryTimeInterval_ms;
extern const NSInteger EOCNetworkServiceDatafileDownloadMaxBackoffRetryAttempts;
extern const NSInteger EOCNetworkServiceDatafileDownloadMaxBackoffRetryTimeInterval_ms;
NS_ASSUME_NONNULL_END

@interface EOCNetworkService : NSObject

/**
 * Download the project config file from remote server
 *
 * @param projectId The project ID of the datafile to download
 * @param backoffRetry Indicates if the exponential backoff retry should be enabled
 * @param fromURL The url to download datafile
 * @param completion The completion block of type EOCHTTPRequestManagerResponse
 */
- (void)downloadProjectConfig:(nonnull NSString *)projectId
                 backoffRetry:(BOOL)backoffRetry
                      fromURL:(nonnull NSURL *)url
            completionHandler:(nullable EOCHTTPRequestManagerResponse)completion;

/**
 * Download the project config file from remote server only if it
 * has been modified.
 *
 * @param projectId The project ID of the exponential the datafile to download
 * @param backoffRetry Indicates if backoff retry should be enabled
 * @param lastModifiedDate The date the datafile was last modified
 * @param fromURL The url to download datafile
 * @param completion The completion block of type EOCHTTPRequestManagerResponse
 */
- (void)downloadProjectConfig:(nonnull NSString *)projectId
                 backoffRetry:(BOOL)backoffRetry
                      fromURL:(nonnull NSURL *)url
                 lastModified:(nonnull NSString *)lastModifiedDate
            completionHandler:(nullable EOCHTTPRequestManagerResponse)completion;

/**
 * Dispatches an event to a url
 * @param params Dictionary of the event parameter values
 * @param backoffRetry Indicates if the exponential backoff retry should be enabled
 * @param url The url to dispatch the event
 * @param completion The completion handler
 */
- (void)dispatchEvent:(nonnull NSDictionary *)params
         backoffRetry:(BOOL)backoffRetry
                toURL:(nonnull NSURL *)url
    completionHandler:(nullable EOCHTTPRequestManagerResponse)completion;

/**
 * Returns the URL path for the datafile of a particular project.
 * @param projectId The project ID of the datafile whose URL path we are looking for.
 */
+ (NSURL * _Nonnull)projectConfigURLPath:(nonnull NSString *)projectId;

@end
