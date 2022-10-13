cmake_minimum_required(VERSION 3.24.2)

project(GMSHmesh)

add_subdirectory(FileManagerCPP)

add_executable(${PROJECT_NAME} main.cpp)

add_library(
  mesh mesh.cpp
  FileManagerCPP FileManagerCPP/FileManagerCPP.cpp
)

target_link_libraries(${PROJECT_NAME}
  mesh
  FileManagerCPP
)
