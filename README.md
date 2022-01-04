# game-engine

# Installation
* Get cmake and make installed
  * On Windows make can be installed with chocolatey
  * On Mac these can be installed with Homebrew
  * On Linux they can be installed with your package manager

Debug mode:
1. `mkdir debug`
2. `cd debug`
3. `cmake .. -G "Unix Makefiles"`
4. `make`
5. `./game-engine`

Release mode (faster):
1. `mkdir release`
2. `cd release`
3. `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release`
4. `make`
5. `./game-engine`

# Problems with installation
- If you encounter any openal32.dll issues on Windows, simply get the installer [here](https://openal.org/downloads/)

# Development
Remember to add new classes to CMakeLists.txt under the add_executable command

To run the program at any point, e.g., when testing new code, simply run the following commands in 
 the debug / release directory created above:
 1. `make`
 2. `./game-engine`

# Game
- multiplayer
- mix between eastward and celeste
