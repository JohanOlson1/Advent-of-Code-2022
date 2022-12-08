cmake_minimum_required(VERSION 3.0.0)
project(AdventOfCode)

include(CTest)
enable_testing()

set(CMAKE_GENERATOR "Unix Makefiles" CACHE INTERNAL "" FORCE)

add_executable(AdventOfCode main.cc)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
