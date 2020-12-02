#----------------------------------------------------------------------------
# Setup the project
cmake_minimum_required(VERSION 2.6 FATAL_ERROR)
project(subtraction)

#----------------------------------------------------------------------------
# Find ROOT package (2018.04.13)
#find_package(ROOT REQUIRED Hist RIO Physics Minuit Minuit2 Gpad)
find_package(ROOT REQUIRED Hist RIO Physics Minuit Gpad)


#----------------------------------------------------------------------------
# Setup ROOT include directories and compile definitions (2018.04.13)
#
include(${ROOT_USE_FILE})





#----------------------------------------------------------------------------
# Locate sources and headers for this project (2018.04.13)
#
include_directories(${PROJECT_SOURCE_DIR}/include
                    ${ROOT_INCLUDE_DIRS})
		    file(GLOB sources ${PROJECT_SOURCE_DIR}/src/*.cpp)
		    file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.hpp)

#----------------------------------------------------------------------------
# Add the executable, and link it to the Geant4 libraries (2018.04.13)
#
add_executable(signal signal.cpp ${sources} ${headers})
target_link_libraries(signal ${ROOT_LIBRARIES})
#target_link_libraries(hit sqlite3)






#----------------------------------------------------------------------------
# For C++ 11 programming 2019.04.22
#

target_compile_options(signal  PRIVATE -std=c++1y)





