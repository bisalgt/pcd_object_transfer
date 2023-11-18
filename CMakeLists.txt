cmake_minimum_required(VERSION 3.5)
project(PointCloudObjTransfer VERSION 0.1.0 LANGUAGES C CXX)
execute_process(COMMAND rm -rf build)
find_package(PCL 1.13 REQUIRED)

include_directories(${PCL_INCLUDE_DIRS})
include_directories(${Vulkan_INCLUDE_DIRS})
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
file(GLOB HELPERS "src/helpers/*.cpp")

link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})


add_executable(PointCloudObjTransfer src/main.cpp ${HELPERS})
target_compile_features(PointCloudObjTransfer PRIVATE cxx_std_17)
target_link_libraries (PointCloudObjTransfer ${PCL_LIBRARIES})

