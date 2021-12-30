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
 src/MusicHandler.cpp
 src/TextSystem.cpp
 src/ParticleSystem.cpp
 src/SoundHandler.cpp
 src/SpriteSheet.cpp
 src/TextBox.cpp
 src/Button.cpp
 src/main.cpp
)

target_link_libraries(
 game-engine
 sfml-graphics
 sfml-audio
)