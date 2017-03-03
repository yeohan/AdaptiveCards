./build_ios/libadaptivecards.xcodeproj: libadaptivecards.gyp ./deps/djinni/support-lib/support_lib.gyp adaptivecards.djinni
	sh ./run_djinni.sh
	deps/gyp/gyp --depth=. -f xcode -DOS=ios --generator-output ./build_ios -Ideps/djinni/common.gypi ./libadaptivecards.gyp

ios: ./build_ios/libadaptivecards.xcodeproj
	xcodebuild -workspace ./AdaptiveCards.xcworkspace \
           -scheme libadaptivecards \
           -configuration 'Debug' \
           -sdk iphonesimulator