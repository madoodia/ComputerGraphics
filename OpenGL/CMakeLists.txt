# -------------------- #
# (C)2022 madoodia.com #
# -------------------- #

cmake_minimum_required (VERSION 3.17)
cmake_policy(VERSION 3.17)

project(LearningOpenGL)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif(WIN32)

include_directories(
	../core2
	../includes
)

link_directories(
	../libs
)

if(WIN32)
  set(LIBS glfw3 glew32 API opengl32)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(WIN32)


set(SOURCES
    main.cpp
)

# if you want to build static library of core2/api2.cpp
add_library(API2 "../core2/api2.cpp")
set(LIBS ${LIBS} API2)

set(NAME LearningOpenGL)
add_executable(${NAME} ${SOURCES})
target_link_libraries(${NAME} ${LIBS})

