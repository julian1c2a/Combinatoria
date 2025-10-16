# Versión mínima de CMake requerida
cmake_minimum_required(VERSION 3.10)

# Nombre del proyecto
project(Combinatoria LANGUAGES CXX)

# Establece el estándar de C++ a C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Agrega el ejecutable y sus archivos fuente
# CMake encontrará automáticamente main.cpp en la misma carpeta
add_executable(Combinatoria main.cpp)