cmake_minimum_required(VERSION 3.10)

project(MPointerProject)

# Establecer la versión de C++
set(CMAKE_CXX_STANDARD 17)

# Agregar el directorio que contiene MPointer.h 
include_directories(${CMAKE_SOURCE_DIR})

# Agregar el ejecutable principal
add_executable(main main.cpp MPointerGC.cpp ListaDoble.h Nodo.h sorting.h)

# Agregar GoogleTest
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Incluir el subdirectorio tests para las pruebas unitarias
add_subdirectory(tests)

# Iniciar las pruebas
add_test(NAME runTests COMMAND runTests)
