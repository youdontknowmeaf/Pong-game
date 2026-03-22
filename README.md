# INSTALLATION

Install the dependencies. Which is just RayLib. You should install the raylib-devel.
https://www.raylib.com/ for help.

Note: if you are a windows user then you are on your own, I can't be bothered less to make a build for such bad system.

1. ``git clone https://github.com/youdontknowmeaf/Pong-game.git``
2. ``cd Pong-game/Pong/YourDesiredVersionHere``
3. Compile the game with ``make`` or doing it manually.
4. To launch the game you write ``./Pong`` and to recompile it you can:
- ``make`` or ``gcc main.c -o out -lraylib -lm`` (for main version)
- ``gcc lightweigh-pong.c -o Lightweigh-Pong -lraylib -lm`` (for lightweigh version)

# GOALS
- Recreating 1972 pong with QOL features
- Making a game so simple it can run on anything with raylib.
- Making a fun project that others can learn from by interacting with user friendly config.

# CHANGELOG
- **pre-v1**:
- First playable version
- **v1.0**:
- Created user friendly configuration
- Created python setup
- Created shell auto-compile
- Reset the pre-defined colors to RED + BLUE
- **v1.1**:
- Added additional features to configuration
- Improved the python script
- Improved shell auto-compile
- Improved the readibility of the configuration
- Rewrote the README.md 
- **v1.1.1**
- Added compile instructions for lightweigh pong
- Added lightweigh pong
- Minor cosmetic changes
- **v1.1.2**
- The game's speed is no longer dependend on FPS
- **v1.2**
- Created a Makefile build system for convinience
- Implemented Zen mode
- Implemented Random Ball Speed when it hits something
- **v2.0**:
- This is a major release as it includes the almost complete rework of the game in C language. (Moving from C++)
- Note: Fuck Rust, Rust devs selfish fucks.
- **v2.1 - Stable**
- This release aims to make the code base more readable by splitting everything into a seprate directory and rewriting/deleting some things like setup.py, which are useless. 
- **v3.0 HUGE UPDATE**
- This update features many cool things...!
- I have rewritten the whole game in C# and made executables for MacOS (intel and silicon), Linux (64 and ARM64, Windows (x86, 64 and ARM64)
- Added support for 32 bit Linux for the main version.
- Reimagined the way I will further dev the game, I will now focus on rewritting the game in various languages.
