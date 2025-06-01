cmake_minimum_required(VERSION 3.25)
project(dSync)

set(CMAKE_CXX_STANDART 17)
set(CMAKE_CXX_EXTENSIONS OFF)

# generate compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)



add_subdirectory(src/server)
#add_subdirectory(src/client)
#add_subdirectory(src/common)
