Pod::Spec.new do |spec|
  spec.name         = "EyeofcloudSDKiOS"
  spec.version      = "0.0.1"
  spec.summary      = "Eyeofcloud SDK for iOS."
  spec.description  = <<-DESC
			Eyeofcloud SDK for iOS(Swift and Objective C) applications. 
                   DESC
  spec.homepage     = "https://github.com/eyeofcloud/EyeofcloudSDKiOS"
  spec.license      = "MIT"
  spec.author             = { "eyeofcloud" => "zhangweixue@heliyuntong.cn" }
  spec.platform     = :ios, "8.0"
  spec.source       = { :git => "https://github.com/eyeofcloud/EyeofcloudSDKiOS.git", :tag => spec.version }
  spec.source_files  = "EyeofcloudSDKiOS/EyeofcloudSDKiOS.framework/Headers/*.{h}"
  
  spec.vendored_frameworks = "EyeofcloudSDKiOS/EyeofcloudSDKiOS.framework"
  spec.frameworks = "AudioToolbox", "CFNetwork","Foundation","MobileCoreServices","Security","SystemConfiguration","UIKit"
  spec.libraries = "icucore", "sqlite3"
end
