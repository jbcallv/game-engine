cmake_minimum_required(VERSION 3.19)
project(game-engine VERSION 1.0)

include_directories(include)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED true)

include(FetchContent)

set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
 SFML
 GIT_REPOSITORY https://github.com/SFML/SFML.git
 GIT_TAG 2.5.1
)

FetchContent_MakeAvailable(SFML)

add_executable(
 game-engine
 src/Joe.cpp
 src/GameManager.cpp
 src/GameState.cpp
 src/MenuState.cpp
 src/PlayingState.cpp
 src/Camera.cpp
 src/Tilemap.cpp
 src/MusicHandler.cpp
 src/ParticleSystem.cpp
 src/SoundHandler.cpp
 src/SpriteSheet.cpp
 src/main.cpp
 src/Gui.cpp
)

target_link_libraries(
 game-engine
 sfml-graphics
 sfml-audio
)