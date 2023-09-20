cmake_minimum_required(VERSION 3.20)

project(tetris-sdl)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)
add_executable(main ${CMAKE_SOURCE_DIR}/src/main.cpp)

set(SDL_LIBRARIES 
  ${CMAKE_SOURCE_DIR}/lib/libSDL2main.a
  ${CMAKE_SOURCE_DIR}/lib/libSDL2.dll.a
  ${CMAKE_SOURCE_DIR}/lib/libSDL2.a
  )

target_link_options(main PRIVATE "-lmingw32")
target_link_libraries(main PRIVATE 
  ${SDL_LIBRARIES}
  )
