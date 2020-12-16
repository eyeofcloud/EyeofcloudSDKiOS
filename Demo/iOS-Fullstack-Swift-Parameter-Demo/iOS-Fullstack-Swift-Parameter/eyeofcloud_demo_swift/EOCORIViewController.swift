//
//  EOCORIViewController.swift
//  eyeofcloud_demo_swift
//
//  Created by edz on 2019/5/17.
//  Copyright © 2019年 edz. All rights reserved.
//

import Foundation
import UIKit
import EyeofcloudSDKiOS

class EOCORIViewController: UIViewController {
    var eocClient: EOCClient?
    
    let appDelegate = UIApplication.shared.delegate as! AppDelegate
   

    @IBOutlet weak var ori: UILabel!
    
    @IBAction func click(_ sender: Any) {
        self.eocClient?.track("用户点击按钮", userId:appDelegate.getUserId()!)
        
        let alertController = UIAlertController(title: "目标事件：用户点击按钮\n已发送", message:
                                                    "UserID: " + appDelegate.getUserId()!, preferredStyle: .alert)
        alertController.addAction(UIAlertAction(title: "Dismiss", style: .default))
        self.present(alertController, animated: true, completion: nil)
        DispatchQueue.main.asyncAfter(deadline: .now() + 3) {
            alertController.dismiss(animated: true, completion: nil)
        }
    }
    override func viewDidLoad() {
        super.viewDidLoad()
        self.eocClient = appDelegate.getEyeofcloud()
        
        let content = self.eocClient?.variableString("text-content",userId:appDelegate.getUserId()!,activateExperiment: true)
        if (content != nil){
            ori.text =  "变量text-content的值:\n" + content!
            ori.numberOfLines = 0
            ori.sizeToFit()
        }else{
            ori.text = "版本A界面"
        }
        ori.center.x = self.view.center.x
        ori.center.y = self.view!.bounds.height/3
        
        for view in self.view.subviews as [UIView] {
            if let btn = view as? UIButton {
                btn.center.x = self.view.center.x
                btn.center.y = self.view!.bounds.height*4/5
            }
        }
        

    }
    
   
    
}
