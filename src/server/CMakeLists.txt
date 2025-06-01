file(GLOB_RECURSE SERVER_SOURCES CONFIGURE_DEPENDS *.cpp *.hpp)

add_executable(server ${SERVER_SOURCES})

#target_link_libraries(server PRIVATE common)

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(server PRIVATE -Wall -Wextra -Wpedantic -Werror)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    target_compile_options(server PRIVATE /W4 /WX)
endif()

