cmake_minimum_required(VERSION 3.22.1)

project("audiocore")

include_directories(
    ../../../../../core/cpp
)

add_library(
             audiocore
             
             SHARED
             
             ../../../../../core/cpp/AudioManager.cpp
             ../../../../../core/cpp/DSP_Filters.cpp
             jni_wrapper.cpp
             )

find_library(log-lib log)

target_link_libraries(audiocore
                      ${log-lib}
                      
                      )
                      
