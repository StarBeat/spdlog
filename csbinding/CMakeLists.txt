# Copyright(c) 2019 spdlog authors Distributed under the MIT License (http://opensource.org/licenses/MIT)

cmake_minimum_required(VERSION 3.10)
project(spdlog_csbinding CXX)

if(NOT TARGET spdlog)
    # Stand-alone build
    find_package(spdlog REQUIRED)
endif()

# ---------------------------------------------------------------------------------------
# Example of using pre-compiled library
# ---------------------------------------------------------------------------------------
add_library(spdlogcs SHARED csbinding.cpp)
target_link_libraries(spdlogcs PRIVATE spdlog::spdlog)

# ---------------------------------------------------------------------------------------
# Example of using header-only library
# ---------------------------------------------------------------------------------------
if(SPDLOG_BUILD_EXAMPLE_HO)
    add_library(spdlogcs SHARED csbinding.cpp)
    target_link_libraries(spdlogcs PRIVATE spdlog::spdlog_header_only)
endif()
