cmake_minimum_required(VERSION 3.20)

project(tetris-sdl)

set(SOURCES 
  ${CMAKE_SOURCE_DIR}/src/main.cpp
  ${CMAKE_SOURCE_DIR}/src/game.cpp
)
include_directories(include)
add_executable(main ${SOURCES})

set(SDL_LIBRARIES 
  ${CMAKE_SOURCE_DIR}/lib/libSDL2main.a
  ${CMAKE_SOURCE_DIR}/lib/libSDL2.a
  ${CMAKE_SOURCE_DIR}/lib/libSDL2_image.a
  )

target_link_options(main PRIVATE "-lmingw32")
target_link_libraries(main PRIVATE 
  ${SDL_LIBRARIES}
  SetupAPI.lib
  Imm32.lib
Winmm.lib
Version.lib
  )
