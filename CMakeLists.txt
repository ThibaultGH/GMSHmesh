cmake_minimum_required(VERSION 3.24.2)

project(GMSHmesh)

add_subdirectory(FileManagerCPP)

# add_executable(${PROJECT_NAME} main.cpp)

find_library(myblaslib gslcblas DOC "GNU Scientific Library (GSL) -- blas library package" REQUIRED)

if(${myblaslib} STREQUAL "myblaslib-NOTFOUND")
  message(FATAL_ERROR "no BLAS lib, sorry")
endif()


# find_library(mylapacklib lapack DOC "LAPACK library")

# if(${mylapacklib} STREQUAL "mylapacklib-NOTFOUND")
#   message(FATAL_ERROR "no LAPACK lib, sorry")
# endif()

add_library(
  mesh mesh.cpp
  FileManagerCPP FileManagerCPP/FileManagerCPP.cpp
)

# target_link_libraries(${PROJECT_NAME}
#   mesh
#   FileManagerCPP
#   # lapack
#   ${myblaslib}
# )
