//
//  EOCORIViewController.swift
//  eyeofcloud_demo_swift
//
//  Created by edz on 2019/5/17.
//  Copyright © 2019年 edz. All rights reserved.
//

import Foundation
import UIKit

class EOCORIViewController: UIViewController {
    var userid : String = ""
    var eocClient: EOCClient?
    
    let appDelegate = UIApplication.shared.delegate as! AppDelegate
   

    @IBOutlet weak var ori: UILabel!
    
    @IBAction func click(_ sender: Any) {
        //ori.text = "目标触发"
        self.eocClient?.track("用户点击按钮", userId: appDelegate.userId,attributes: appDelegate.getUserAttributes()!)
        
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
