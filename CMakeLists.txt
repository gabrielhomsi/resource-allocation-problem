cmake_minimum_required(VERSION 3.4)
project(rap)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -DIL_STD -O4")

file(GLOB SOURCE_FILES "src/*.cpp")

include_directories(
        /opt/ibm/ILOG/CPLEX_Studio1263/cplex/include
        /opt/ibm/ILOG/CPLEX_Studio1263/concert/include
        /opt/mosek/7/tools/platform/linux64x86/h
)

link_directories(
        /opt/ibm/ILOG/CPLEX_Studio1263/cplex/lib/x86-64_linux/static_pic
        /opt/ibm/ILOG/CPLEX_Studio1263/concert/lib/x86-64_linux/static_pic
        /opt/mosek/7/tools/platform/linux64x86/bin
)

set(EXECUTABLE_OUTPUT_PATH "release")

add_executable(rap ${SOURCE_FILES})

target_link_libraries(
        rap
        boost_program_options
        ilocplex
        concert
        cplex
        m
        pthread
        mosek64
)