cmake_minimum_required(VERSION 3.0)

project(${PROJECT_NAME})

MESSAGE( STATUS "SOURCES_DIR:         " ${SOURCES_DIR})

file(GLOB project_srcs
  "${SOURCES_DIR}/*.h"
  "${SOURCES_DIR}/*.cpp"
)

add_executable(${PROJECT_NAME} ${project_srcs})
set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "${COMMON_CFLAGS}" LINK_FLAGS "${COMMON_LFLAGS}")
