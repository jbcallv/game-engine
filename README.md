# game-engine

# Installation
* Get cmake and make installed
  * On Windows make can be installed with chocolatey
  * On Mac these can be installed with Homebrew
  * On Linux they can be installed with your standard package manager
1. `mkdir debug`
2. `cd debug`
3. `cmake .. -G "Unix Makefiles"` or `cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release` for release mode
4. `make`
5. `./game-engine`

# Problems with installation
- If you encounter any openal32.dll issues on Windows, simply get the installer [here](https://openal.org/downloads/)

# Development
- Remember to add new classes to CMakeLists.txt under the add_executable command
