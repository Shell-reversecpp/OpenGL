cmake_minimum_required(VERSION 3.15)

add_library(GLAD STATIC
        ${CMAKE_CURRENT_LIST_DIR}/include/glad/glad.h
        ${CMAKE_CURRENT_LIST_DIR}/src/glad.c
        ${CMAKE_CURRENT_LIST_DIR}/include/KHR/khrplatform.h
)

target_include_directories(GLAD PUBLIC ${CMAKE_CURRENT_LIST_DIR}/include)