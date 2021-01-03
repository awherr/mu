cmake_minimum_required(VERSION 3.19)
project(mu)

set(THIRD_PARTY_DIR ${CMAKE_SOURCE_DIR}/third_party)

include_directories(
    ${THIRD_PARTY_DIR}/cli11/include
)

add_subdirectory(vm)

