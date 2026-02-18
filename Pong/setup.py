from os import system as cmd

a = input("Is raylib installed? (Y/n) ")
if a != "y" or a != "":
    print("""Please install raylib.
            Fedora:
            sudo dnf install raylib raylib-devel
            Arch Linux:
            sudo pacman -S raylib
            OpenSUSE:
            zypper in raylib-devel

        Other distros:
        https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux""")
else:
    print("Attempting to build the game...")
    try:
        cmd("./build.sh")
        print(
            "Likely ran succesfuly! Open the game with ./out or make a desktop shortcut. You can now delete this file."
        )
    except:
        print(
            "Failed to build. Too fucking bad... Make sure RayLib and g++ are installed and working!"
        )
        print("Testing g++...")
        cmd("g++ -v")
