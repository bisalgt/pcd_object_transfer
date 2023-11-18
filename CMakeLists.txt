cmake_minimum_required(VERSION 3.5)
project(PointCloudObjTransfer VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/src)
file(GLOB HELPERS "src/helpers/*.cpp")

enable_testing()

add_executable(PointCloudObjTransfer src/main.cpp ${HELPERS})
target_compile_features(PointCloudObjTransfer PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
