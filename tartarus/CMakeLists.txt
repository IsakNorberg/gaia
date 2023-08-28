
include_directories(include)

add_library(tartarusLib STATIC sorce/brain.cpp sorce/dynamicIndividual.cpp
       sorce/Individual.cpp sorce/tartarus.cpp sorce/random.cpp sorce/population.cpp)
target_link_directories(tartarusLib PRIVATE include)