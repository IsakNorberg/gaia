cmake_minimum_required(VERSION 3.24)
project(gaia)

set(CMAKE_CXX_STANDARD 23)

include_directories(tartarus/include)
include_directories(test)
include_directories(test/build)
include_directories(test/build/gaia)
include_directories(test/build/gaia/debug)
include_directories(test/include)


add_executable(gaia
        tartarus/sorce/brain.cpp
        tartarus/sorce/dynamicIndividual.cpp
        tartarus/sorce/Individual.cpp
        tartarus/sorce/population.cpp
        tartarus/sorce/random.cpp
        tartarus/sorce/tartarus.cpp
        test/sorce/test.cpp
        main_build_test/main.cpp)

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest
        GIT_TAG release-1.11.0
)
FetchContent_GetProperties(googletest)

if(NOT googletest_POPULATED)
    FetchContent_Populate(googletest)
    add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif ()

target_link_libraries(gaia gtest_main gmock_main)






