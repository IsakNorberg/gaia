include_directories(include)
add_library(testS STATIC sorce/test.cpp)
target_include_directories(testS PUBLIC include)


