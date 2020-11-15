cmake_minimum_required(VERSION 3.1.3)

project(Aud)

set(INCLUDE_FOLDER include)
set(HEADER_FILES ${INCLUDE_FOLDER}/intlist.h ${INCLUDE_FOLDER}/list.h)
set(SOURCES ${INCLUDE_FOLDER}/intlist.c)

add_library(lib STATIC ${SOURCES} ${HEADER_FILES})
target_include_directories(lib PUBLIC ${INCLUDE_FOLDER})

add_executable(aud10 Aud10.c)
add_executable(aud11 Aud11.c)
target_link_libraries(aud10 lib)
target_link_libraries(aud11 lib)
