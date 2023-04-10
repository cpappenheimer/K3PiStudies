cmake_minimum_required(VERSION 3.24)

### project
project(K3PiStudies VERSION 1.0
        LANGUAGES CXX)

### find packages
find_package(ROOT 6.16 CONFIG REQUIRED)
find_package(Boost 1.50 REQUIRED COMPONENTS filesystem)

### get path to include dirs
cmake_path(GET CMAKE_CURRENT_SOURCE_DIR PARENT_PATH K3PISTUDIES_ROOT_DIR)
set(K3PISTUDIES_INC_DIR "${K3PISTUDIES_ROOT_DIR}/include")

### add executable
add_executable(K3PiStudies K3PiStudies.cpp "${K3PISTUDIES_INC_DIR}")
set_target_properties(K3PiStudiesUtils PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
)

### include dirs
target_include_directories(K3PiStudies PUBLIC 
                            "${K3PISTUDIES_INC_DIR}")

### add required ext libs
target_link_libraries(K3PiStudies PUBLIC 
                        K3PiStudiesUtils)
target_link_libraries(K3PiStudies PUBLIC 
                        CLI11::CLI11
                        Boost::filesystem
                        ROOT::Core
                        ROOT::MathCore
                        ROOT::TreePlayer
                        ROOT::Physics)
#target_link_libraries(K3PiStudies INTERFACE
#                        LHCbStyle)                         