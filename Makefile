# -- [ Standard (Linux) ] \\

CXX = gcc
CSTD = -std=c89 -pedantic 
CXXFLAGS = -Wall -O2
CXXLIBS = `sdl-config --cflags --libs` 
TARGET = Pong.out
SOURCE = main.c

all: $(TARGET)

# -- [ Windows 95/98/DOS ] \\

win_9x_DOS: CXX         =       i686-w64-mingw32-gcc
win_9x_DOS: TARGET      =       Pong_w95_i386.exe
win_9x_DOS: CXXFLAGS    =       -march=i386 -mtune=i386 -O2
win_9x_DOS: CXXLIBS     =       -I./sdl-win95/include -L./sdl-win95/lib -lmingw32 -lSDLmain -l:libSDL.a -mwindows \
	-lwinmm -lgdi32 -ldxguid # also comment out these for dynamic exe.
#replace -l:libSDL.a with -lSDL for dynamic exe and copy the SDL.dll to the dir with executable
win_9x_DOS: $(TARGET)

# -- [ Compile ] \\

$(TARGET): $(SOURCE)
	$(CXX) $(CSTD) $(SOURCE) -o $(TARGET) $(CXXLIBS) $(CXXFLAGS)
	@if [ "$(CXX)" = "i686-w64-mingw32-gcc" ]; then cp ./sdl-win95/bin/SDL.dll .; fi

clean:
	rm -f *.out *.exe *.dll
