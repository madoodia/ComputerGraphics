# -------------------- #
# (C)2022 madoodia.com #
# -------------------- #

cmake_minimum_required (VERSION 3.17)
cmake_policy(VERSION 3.17)

project($ENV{PROJECT_NAME})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

if(WIN32)
	set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
endif(WIN32)

include_directories(
	../includes
)

link_directories(
	../libs
)

if(WIN32)
  set(LIBS)
  add_definitions(-D_CRT_SECURE_NO_WARNINGS)
endif(WIN32)

set(SOURCES
  "$ENV{ROOT}/$ENV{BASENAME}/$ENV{FILENAME}.cpp"
)

add_executable($ENV{PROJECT_NAME} ${SOURCES})
target_link_libraries($ENV{PROJECT_NAME} ${LIBS})
