//
//  AppDelegate.swift
//  eyeofcloud_demo_swift
//
//  Created by edz on 2019/5/7.
//  Copyright © 2019年 edz. All rights reserved.
//

import UIKit
import EyeofcloudSDKiOS


@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate {
    
    var window: UIWindow?
    
    private var eocManager: EOCManager?
    var userAttributes : [String : String] = [:]
    var userId = String(Int(arc4random_uniform(300000)))
    
    // customizable settings
    let datafileName = "config" // default parameter for initializing Eyeofcloud from saved datafile
    var projectId = "8_3e9f2898e924f4961afb27b57ee7da08" // project name: X Mobile - Sample App
    var experimentKey = "iOS-param"
    var eventKey = "点击按钮"
    let attributes = ["test":"abc", "test03":"def"]
    let eventDispatcherDispatchInterval = 1000
    let datafileManagerDownloadInterval = 600

    
    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        // ---- Create the Event Dispatcher ----
        let eventDispatcher = EOCEventDispatcherDefault(builder : EOCEventDispatcherBuilder(block: { (builder) in
            builder?.eventDispatcherDispatchInterval = self.eventDispatcherDispatchInterval
            builder?.logger = EOCLoggerDefault.init(logLevel: .debug)
        }))
        
        // ---- Create the Datafile Manager ----
        let datafileManager = EOCDatafileManagerDefault(builder: EOCDatafileManagerBuilder(block: { (builder) in
            builder!.datafileFetchInterval = TimeInterval(self.datafileManagerDownloadInterval)
            builder!.projectId = self.projectId
        }))
        
        let builder = EOCManagerBuilder(block: { (builder) in
            builder!.projectId = self.projectId
            builder!.datafileManager = datafileManager!
            builder!.eventDispatcher = eventDispatcher
        })
        //---- Create eoc Manager ----
        eocManager = EOCManager.init(builder: builder)
        // ---- 1. Asynchronous Initialization -----
        eocManager?.initialize(callback: { [weak self] (error, eyeofcloudClient) in
            let variation = eyeofcloudClient?.activate((self?.experimentKey)!, userId: (self?.userId)!, attributes: (self?.attributes))

	        self?.setRootViewController(bucketedVariation:variation)
        })
        
        // ---- 2. Synchronous Initialization with Datafile ----
        // load the datafile from the app bundle
//        let bundle = Bundle.init(for: self.classForCoder)
//        let filePath = bundle.path(forResource: datafileName, ofType: "json")
//        var jsonDatafile: Data? = nil
//        do {
//            let fileContents = try String.init(contentsOfFile: filePath!, encoding: String.Encoding.utf8)
//            jsonDatafile = fileContents.data(using: String.Encoding.utf8)!
//        }
//        catch {
//            print("invalid JSON Data")
//        }
//
//        let eyeofcloudClient : EOCClient? = eocManager?.initialize(withDatafile:jsonDatafile!)
//        let variation = eyeofcloudClient?.activate(self.experimentKey, userId:self.userId, attributes: self.attributes)
//        self.setRootViewController(bucketedVariation:variation)
        
        // --- 3. Synchronous Initialization with Saved Datafile ----
        //       let eyeofcloudClient = eocManager?.initialize()
        //       let variation = eyeofcloudClient?.activate(self.experimentKey, userId:self.userId, attributes: self.attributes)
        //       self.setRootViewController(bucketedVariation:variation)
        
        return true
    }
    
    func setRootViewController(bucketedVariation:EOCVariation?) {
        DispatchQueue.main.async {
            
            var storyboard : UIStoryboard
            
            storyboard = UIStoryboard(name: "Main", bundle: nil)

            let rootViewController = storyboard.instantiateViewController(withIdentifier: "EOCORIViewController")
            
            if let window = self.window {
                window.rootViewController = rootViewController
            }
        }
    }
    func getEOCManager() -> EOCManager? {
        return eocManager
    }
    
    func getEyeofcloud() -> EOCClient? {
        return eocManager?.getEyeofcloud()
    }
    
    func getUserId() -> String? {
        return userId
    }
    
    func getUserAttributes() -> [String : String]? {
        userAttributes = [
            "Gender": "female"
        ]
        return userAttributes
    }
    func applicationWillResignActive(_ application: UIApplication) {
        // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
        // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
    }
    
    func applicationDidEnterBackground(_ application: UIApplication) {
        // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
        // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
    }
    
    func applicationWillEnterForeground(_ application: UIApplication) {
        // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
    }
    
    func applicationDidBecomeActive(_ application: UIApplication) {
        // Restart any tasks that were paused (or not yet started) while the application was inactive. If the application was previously in the background, optionally refresh the user interface.
    }
    
    func applicationWillTerminate(_ application: UIApplication) {
        // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
    }
    
    
}

