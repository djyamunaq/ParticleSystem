cmake_minimum_required(VERSION 2.8.12)
project (ParticleSystem)

find_package (Eigen3 3.4 REQUIRED)
find_package(OpenCV REQUIRED)

set (CMAKE_SHARED_LINKER_FLAGS "-pthread")
set (CMAKE_CXX_FLAGS "-g")

add_library(ParticleSystem STATIC ${CMAKE_SOURCE_DIR}/src/ParticleSystem.cpp)
target_include_directories(ParticleSystem PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(ParticleSystem PUBLIC Eigen3::Eigen)

add_library(Particle STATIC ${CMAKE_SOURCE_DIR}/src/Particle.cpp)
target_include_directories(Particle PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(Particle PUBLIC Eigen3::Eigen)

add_executable(example ${CMAKE_SOURCE_DIR}/example.cpp)
target_include_directories(example PUBLIC ${CMAKE_SOURCE_DIR}/include)
target_include_directories(example PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(example PUBLIC Eigen3::Eigen)
target_link_libraries(example PUBLIC ParticleSystem)
target_link_libraries(example PUBLIC Particle)
target_link_libraries(example PUBLIC ${OpenCV_LIBS})
