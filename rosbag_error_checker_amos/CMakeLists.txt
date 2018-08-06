project(rosbag_error_checker)
cmake_minimum_required(VERSION 2.8.3)

set(CMAKE_BUILD_TYPE Release)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(CMAKE_VERBOSE_MAKEFILE ON)

set(CMAKE_CXX_FLAGS_DEBUG "-DDEBUG")
set(COMPILER_OPTIONS ${COMPILER_OPTIONS} -g)

find_package(gflags REQUIRED)
find_package(glog REQUIRED)
find_package(CSM)
find_package(OpenCV REQUIRED)
find_package(Eigen3 REQUIRED)
find_package(cartographer REQUIRED)
include("${CARTOGRAPHER_CMAKE_DIR}/functions.cmake")
set(BUILD_SHARED_LIBS OFF)
google_initialize_cartographer_project()

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS
    system
    filesystem
    log
    log_setup
    thread
    date_time
    chrono
    iostreams
    serialization
    timer
    REQUIRED
    )

find_package(LuaGoogle REQUIRED)

find_package(catkin REQUIRED COMPONENTS
    roscpp
    std_msgs
    pita_base
    pita_consist
    pita_slam
    rosbag
    )

catkin_package(
    LIBRARIES ${PROJECT_NAME}
    CATKIN_DEPENDS roscpp std_msgs pita_base pita_consist pita_slam
    #  DEPENDS system_lib
)

include_directories(
    ${catkin_INCLUDE_DIRS}
    ${pita_base_INCLUDE_DIRS}
    ${pita_consist_INCLUDE_DIRS}
    ${pita_slam_INCLUDE_DIRS}
    ${EIGEN3_INCLUDE_DIR}
    ${LUA_INCLUDE_DIR}
    ${CSM_INCLUDE_DIR}
    ${Boost_INCLUDE_DIRS}
)

set(CARTOGRAPHER_LIBS cartographer ${Boost_LIBRARIES})

foreach(component base consist slam)
    foreach(path ${pita_${component}_INCLUDE_DIRS})
        include_directories(${path}/pita_${component})
    endforeach()
endforeach()

add_compile_options(-std=c++11 -Wall -O3 -lpthread -pthread -g)

set (SOURCE_FILES src/rosbag_error_checker.cpp 
                  src/rosbag_error_checker.h )

add_executable(rosbag_error_checker
    src/rosbag_error_checker.cpp
        )

target_link_libraries(
    rosbag_error_checker
    ${catkin_LIBRARIES}
    ${OpenCV_LIBS}
    gflags
    glog
    ${Boost_LIBRARIES}
    ${CARTOGRAPHER_LIBS}
    ${PYTHON_LIBRARIES}
    ${pita_base_LIBRARIES}
    ${pita_consist_LIBRARIES}
    ${pita_slam_LIBRARIES}
)

#add_dependencies(rosbag_error_checker pita_slam)
