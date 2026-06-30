project(Pong LANGUAGES C)

cmake_minimum_required(VERSION 3.20)

add_executable(Pong)
target_sources(Pong PRIVATE main.c)

#find_package(raylib REQUIRED)
target_link_libraries(Pong PRIVATE raylib)

option(STATIC_LINUX "Build with RayLib baked into the executable. (Linux)" OFF)

if(STATIC_LINUX)
target_include_directories(Pong PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/../Lightweigh/libraylib/linux)
target_link_libraries(Pong PRIVATE -Wl,-Bstatic raylib -Wl,-Bdynamic m dl pthread rt X11)
elseif(UNIX)
target_link_libraries(Pong PRIVATE m X11 GL pthread dl rt)
elseif(WIN32)
target_link_libraries(Pong PRIVATE winmm opengl32 gdi32)
elseif(OSX)
target_link_libraries(Pong PRIVATE "-framework IOKit" "-framework Cocoa" "-framework OpenGL" m)
endif()
