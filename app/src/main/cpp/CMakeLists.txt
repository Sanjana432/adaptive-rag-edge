cmake_minimum_required(VERSION 3.22.1)
project("llamma_jni")
add_library(llamma_jni SHARED llamma_jni.cpp)
target_link_libraries(llamma_jni android log)
