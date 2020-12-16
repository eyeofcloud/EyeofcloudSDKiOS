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

#ifndef UNIVERSAL
    #import <EyeofcloudSDKCore/EyeofcloudSDKCore.h>
#endif
#import "EOCClient.h"
#import "EOCClientBuilder.h"
#if TARGET_OS_IOS
    #import "EOCDatabase.h"
    #import "EOCDatabaseEntity.h"
#endif
#import "EOCDataStore.h"
#import "EOCDatafileManagerBasic.h"
#import "EOCFileManager.h"
#import "EOCManagerBase.h"
#import "EOCManagerBasic.h"
#import "EOCManagerBuilder.h"

#if TARGET_OS_IOS
#import "EOCFMDBDatabase.h"
#import "EOCFMDBDatabaseQueue.h"
#import "EOCFMDB.h"
#import "EOCFMDBResultSet.h"
#endif

//! Project version number for EyeofcloudSDKShared.
FOUNDATION_EXPORT double EyeofcloudSDKSharedVersionNumber;

//! Project version string for EyeofcloudSDKShared.
FOUNDATION_EXPORT const unsigned char EyeofcloudSDKSharedVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <EyeofcloudSDKShared/PublicHeader.h>


