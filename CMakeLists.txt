cmake_minimum_required(VERSION 3.1.3)

project(Aud)

set(INCLUDE_FOLDER include)

add_library(hash STATIC ${INCLUDE_FOLDER}/hash.c ${INCLUDE_FOLDER}/hash.h)
add_library(list ${INCLUDE_FOLDER}/intlist.c ${INCLUDE_FOLDER}/intlist.h ${INCLUDE_FOLDER}/list.h)
add_library(vector ${INCLUDE_FOLDER}/vector.c  ${INCLUDE_FOLDER}/vector.h)
add_library(utils ${INCLUDE_FOLDER}/utils.c ${INCLUDE_FOLDER}/utils.h)
add_library(str ${INCLUDE_FOLDER}/str.c ${INCLUDE_FOLDER}/str.h)

target_include_directories(hash PUBLIC ${INCLUDE_FOLDER})
target_include_directories(list PUBLIC ${INCLUDE_FOLDER})
target_include_directories(vector PUBLIC ${INCLUDE_FOLDER})
target_include_directories(utils PUBLIC ${INCLUDE_FOLDER})
target_include_directories(str PUBLIC ${INCLUDE_FOLDER})

add_executable(aud10.out Aud10.c)
add_executable(aud12.out Aud12.c)
add_executable(aud13.out Aud13.c)
add_executable(aud14.out Aud14.c)

target_link_libraries(aud10.out vector list)
target_link_libraries(aud12.out vector utils)
target_link_libraries(aud13.out vector str utils)
target_link_libraries(aud14.out hash)
