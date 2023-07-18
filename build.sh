#/bin/bash

rm -r build
mkdir build && cd build 

cmake -DCMAKE_TOOLCHAIN_FILE=$ANDROID_NDK/build/cmake/android.toolchain.cmake \
	-DANDROID_ABI="arm64-v8a" \
	-DANDROID_PLATFORM=android-22 \
	..

make
adb push neon_test /data/local/tmp/tomasran/
