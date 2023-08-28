cmake_minimum_required(VERSION 3.24)
project(gaia)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(tartarus)
add_subdirectory(test)

include_directories(tartarus/include)

add_executable(gaia
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

target_link_libraries(gaia gtest_main gmock_main tartarusLib)
#target_link_libraries(testS gtest_main gmock_main tartarusLib)







