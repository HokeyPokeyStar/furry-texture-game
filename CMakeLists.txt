cmake_minimum_required(VERSION 3.6)
project(Demo)

set(CMAKE_CXX_STANDARD 11) # We need C++11 

find_package(glfw3 REQUIRED)
find_package(GLEW REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(Demo main.cpp)

include_directories(${GLEW_INCLUDE_DIRS})

target_link_libraries(Demo
                      glfw
					  ${GLEW_LIBRARIES}
                      ${CMAKE_DL_LIBS}
					  ${OPENGL_LIBRARIES})

set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${CMAKE_PROJECT_NAME})
