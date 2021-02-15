cmake_minimum_required (VERSION 3.8)

project ("RelSplit")

set(CMAKE_CXX_STANDARD 20)

# Add source to this project's executable.
add_executable (RelSplit
"source/low/LowRel.hpp"
"source/low/LowRel.cpp"
 "source/RelFile.hpp" "source/types.hpp" "source/main.cpp")

#target_include_directories(KuriboConverter PRIVATE "source" "vendor")
