cmake_minimum_required(VERSION 3.24)
#set(CMAKE_VERBOSE_MAKEFILE ON)

### Require out-of-source builds
file(TO_CMAKE_PATH "${PROJECT_BINARY_DIR}/CMakeLists.txt" LOC_PATH)
if(EXISTS "${LOC_PATH}")
    message(FATAL_ERROR "You cannot build in a source directory (or any directory with a CMakeLists.txt file). Please make a build subdirectory.")
endif()

### project
project(K3Pi VERSION 1.0
        LANGUAGES CXX)

### C++ version
set(CMAKE_CXX_STANDARD 17) # ROOT uses C++17
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

### find required packages
find_package(ROOT 6.16 CONFIG REQUIRED)
message(STATUS "Found ROOT ${ROOT_VERSION} at ${ROOT_INCLUDE_DIRS}")
find_package(Boost 1.50 REQUIRED COMPONENTS filesystem)

### git config
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.git")
  # update submods
  message(STATUS "Submodule update...")
  execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init 
                    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                    RESULT_VARIABLE GIT_SUBMOD_RESULT)
  if(NOT GIT_SUBMOD_RESULT EQUAL "0")
    message(FATAL_ERROR
            "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
  endif() # if error updating submods

  # git version number
  execute_process(COMMAND ${GIT_EXECUTABLE} rev-parse --short HEAD
                  WORKING_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}"
                  OUTPUT_VARIABLE PACKAGE_GIT_VERSION
                  ERROR_QUIET
                  OUTPUT_STRIP_TRAILING_WHITESPACE)
endif() # if git found and git dir exists

### add subdirs
add_subdirectory("extern/CLI11")
#add_subdirectory("extern/lhcbstyle/")
add_subdirectory("extern/k3pi_utilities/src")
add_subdirectory("angular_dists/src")