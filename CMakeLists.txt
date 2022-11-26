cmake_minimum_required(VERSION 3.0.0)
project(tdp005) #byta namn senare?

#standart 17++
set(CXX_STANDARD 20)
set(CXX_STANDARD_REQUIRED true)

#complierings flaggor 
add_compile_options(

  -Wall     -Wextra
  -pedantic -Weffc++
  -Wold-style-cast
  -Woverloaded-virtual 
  -fmax-errors=5
  -fdiagnostics-color=always

  )

#alla src fil 
file(GLOB SOURCE 
  "src/*/*.c" "src/*/*.cc" "src/*/*.cpp" "src/*/*.cxx"
  "src/*.c" "src/*.cc" "src/*.cpp" "src/*.cxx"
  "include/**/*.h" "include/**/*.hh" "include/**/*.hpp" "include/**/*.tcc"
  "include/*.h" "include/*.hh" "include/*.hpp" "include/*.tcc"
  )

#skapar körbar fil 
add_executable(${PROJECT_NAME} ${SOURCE})

#libs utanför projekt 
target_link_libraries(${PROJECT_NAME} PRIVATE 
  "sfml-window"
  "sfml-graphics"
  "sfml-system"
  "sfml-audio"
  )

#lägger till .h fil
target_include_directories(${PROJECT_NAME} PRIVATE include/)

