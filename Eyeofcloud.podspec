Pod::Spec.new do |spec|
  spec.name         = "Eyeofcloud"
  spec.version      = "0.0.4"
  spec.summary      = "Eyeofcloud SDK for iOS."
  spec.description  = <<-DESC
			Eyeofcloud SDK for iOS(Swift and Objective C) applications. 
                   DESC
  spec.homepage     = "https://github.com/eyeofcloud/EyeofcloudSDKiOS"
  spec.license      = "MIT"
  spec.author             = { "eyeofcloud" => "zhangweixue@heliyuntong.cn" }
  spec.platform     = :ios, "9.0"
  spec.source       = { :git => "https://github.com/eyeofcloud/EyeofcloudSDKiOS.git", :tag => spec.version }
  spec.source_files  = "EyeofcloudSDKiOS.framework/Headers/*.{h}"
  spec.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  spec.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64' }
  
  spec.vendored_frameworks = "EyeofcloudSDKiOS.framework"
  spec.frameworks = "Foundation"
  spec.preserve_paths = 'EyeofcloudSDKiOS.framework'
  spec.requires_arc = true

end
