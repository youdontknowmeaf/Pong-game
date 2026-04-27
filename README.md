# INSTALLATION
Install the dependencies. Which is just RayLib. You should install the raylib-devel.
https://www.raylib.com/ for help.

# SHITDOWS INSTALL
 Note if you are a windows user:
~~Instead of that you can use the C# build which is direct copy. Download the source code, enter this path ``Pong\Spins\Csharp\Bin\Release\net8.0``, from here you can pick the architecture of your system. Win-* (64 is x86_64, x86 is 32 bit, ARM64 is... ARM64). After opening the folder with your desired architecture you want to enter ``publish`` which will contain the .exe and the DLL.
To mac users: I am afraid you are on your own. As much as I want to help y'all I don't know how to make .dmg apps.~~
Install dotnet, open powershell in the C# directory and run this:
``dotnet publish -r win-x64 -c Release --self-contained``
It will make a x86_64 release for your shitdows system in Bin\Release\net8.0\win-x64\publish\ and there will be .dll and .exe
You can then make a shortcut to it on your homescreen.
Right click on your desktop > new > shortcut > C:\Path\To\The\Fucking\Pong.exe > next and you can give it some kewl icon and name. Then you are done. (All that shit is avoidable with simple ``make`` on linux btw) 

# NORMAL SYSTEMS INSTALL
1. ``git clone https://github.com/youdontknowmeaf/Pong-game.git``
2. ``cd Pong-game/Pong/YourDesiredVersionHere``
3. Compile the game with ``make`` or doing it manually.
4. To launch the game you write ``./Pong`` and to recompile it you can:
- ``make`` or ``gcc main.c -o out -lraylib -lm`` (for main version)
- ``make`` or ``gcc lightweigh-pong.c -o Lightweigh-Pong -lraylib -lm`` (for lightweigh version)

If you are a Mac user, I am currently testing Makefiles for MacOS. (Comming soon)

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
- **v3.5 - Java**
- This update brings us a release made in Java!
- I rewrote the game in Java and added build instructions for Spins.
- Planning Android supprot maybe...?
- **3.6 - Python release**
- Rewrote the game in shitty but popular Python language. (see Spins/Python/how_to_run.txt)
- **3.7 - Zig release**
- Rewrote the game in Zig which led me to Brain Damage. (see Spins/Zig/How2Run.txt)
- **3.8 - Pretty Basic**
- Rewrote the game in FreeBASIC which took a reasonable ammount of time! (see Spins/FreeBasic/HOWTORUN.txt)
- *pre-4.0*
- Started rewriting the game using SDL1.2 and rearranged the folders structure for future updates.
- *pre-4.0v2*
- Rewrote the initial minimal game in SDL1.2 and wrote proper Makefile for it.
- **4.0 - Feather**
- After checking the previous mini releases, they all work.
- __Implemented RayLib 6.0 software rendering to Lightweigh release__
- SDL release is not yet fully complete but it's working and is playable.
- **4.1**
- Added sounds to the Main release and Lightweigh release
- Extended python's Spin functionality with config
