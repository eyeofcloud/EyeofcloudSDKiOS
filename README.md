# Eyeofcloud iOS SDK

This repository houses the iOS SDK for use with Eyeofcloud Full Stack.

Eyeofcloud Full Stack is A/B testing and feature flag management for product development teams.


## Getting Started


### Requirements
* iOS 8.0+ 

### Installing the SDK
 

**note: if you or another framework are using sqlite, then you should probably add compiler options for thead safe sqlite: SQLITE_THREADSAFE=1
https://www.sqlite.org/threadsafe.html

#### Cocoapod 
1. Add the following lines to the _Podfile_:<pre>
    ```use_frameworks!```
    ```pod 'Eyeofcloud', '~> 1.4.4'```
</pre>

2. Run the following command: <pre>``` pod install ```</pre>

Further installation instructions for Cocoapods: https://guides.cocoapods.org/using/getting-started.html


### Samples
A sample code for SDK initialization and experiments:

```
#import <EyeofcloudSDKiOS/EyeofcloudSDKiOS.h>

// Initialize EOCManager
EOCManager *eocManager = [EOCManager init:^(EOCManagerBuilder * _Nullable builder) {
	builder.projectId = @"8_3e9f2898e924f4961afb27b57ee7da08";
}];

// Initialize EOCClient
[eocManager initialize];

// Distribution Variation
EOCClient *eocClient = [eocManager getEyeofcloud];

EOCVariation *variation = [eocClient activate:@"Experiment Name" userId:@"UserName/ID" attributes:@{@"Equipment type":@"iPhone SE"}];

if ([variation.variationKey isEqualToString:@"Original Variation"]) {
	// do something for Original Variation
} else if ([variation.variationKey isEqualToString:@"Optimized Variation #1"]) {
	// do something for Optimized Variation #1
}

// Tracking target events
[eocClient track:@"Target Events" userId:@"UserName/ID" attributes:@{@"Equipment type":@"iPhone SE"}];
		

```


### Further References

1. User Manuals: 
https://www.eyeofcloud.com/user_help#tab-%E7%A7%BB%E5%8A%A8%E7%AB%AFab%E6%B5%8B%E8%AF%95

2. Development Guidance: 
https://www.eyeofcloud.com/help/x/solutions/sdks/introduction/index.html?language=objectivec&platform=mobile 
