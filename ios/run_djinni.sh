#! /usr/bin/env bash

base_dir=$(cd "`dirname "0"`" && pwd)
cpp_out="$base_dir/generated-src/cpp"
objc_out="$base_dir/generated-src/objc"
namespace="AdaptiveCards"
objc_prefix="AC"
djinni_file="adaptivecards.djinni"

deps/djinni/src/run \
   --cpp-out $cpp_out \
   --cpp-namespace $namespace \
   \
   --objc-out $objc_out \
   --objc-type-prefix $objc_prefix \
   \
   --objcpp-out $objc_out \
   \
   --idl $djinni_file
