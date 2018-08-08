cmake_minimum_required(VERSION 3.9)

project(hdepkiosk)

#use C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#get vcpkg path
set(VCPKG_PATH $ENV{VCPKG_PATH})
if(NOT VCPKG_PATH)
    message(FATAL_ERROR "Set VCPKG_PATH environment variable")
endif()

# Define paths based on OS differences
if(OSX)
    set(VCPKG_DISTRO_TYPE x64-osx)
    set(VCPKG_INCLUDE_PATH ${VCPKG_PATH}/installed/${VCPKG_DISTRO_TYPE}/include)
    set(VCPKG_LIBRARY_PATH ${VCPKG_PATH}/installed/${VCPKG_DISTRO_TYPE}/lib)

    #include vcpkg toolchain and add include dirs
    include(${VCPKG_PATH}/scripts/buildsystems/vcpkg.cmake)
    include_directories(${VCPKG_PATH}/installed/x64-osx/include)
elseif(LINUX)
endif()

# Allow CMake to find FindSFML.cmake & FindSFGUI.cmake
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH}) 

# Find SFML 2.4
find_package(SFML 2.4 REQUIRED graphics window system)
if(NOT SFML_FOUND)
    message(FATAL_ERROR "SFML NOT FOUND")
endif()

# Find SFGUI
find_package(SFGUI 0.3 REQUIRED)
if(NOT SFGUI_FOUND)
    message(FATAL_ERROR "SFGUI not found.")
endif()

# Find GTest
find_package(GTest REQUIRED)
if (NOT GTest_FOUND)
    message(FATAL_ERROR "GTest not found.")
endif()

include_directories(src)

add_executable(example1 src/example1.cpp)

target_link_libraries(example1 PUBLIC ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})