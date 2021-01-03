cmake_minimum_required(VERSION 3.19)
project(mu)

set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third_party)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    ${THIRD_PARTY_DIR}/cli11/include
    ${CMAKE_SOURCE_DIR}/libmu/include
    ${CMAKE_SOURCE_DIR}/libviewmu/include
)

add_subdirectory(libviewmu)
add_subdirectory(libmu)
add_subdirectory(simu)
