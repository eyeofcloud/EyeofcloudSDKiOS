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



