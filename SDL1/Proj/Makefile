CXX = gcc
CSTD = -std=c89 -pedantic
CXXFLAGS = -Wall -O2
CXXLIBS = `sdl-config --cflags --libs` 
TARGET = Pong
SOURCE = main.c
$(TARGET): $(SOURCE)
	$(CXX) $(CSTD) $(SOURCE) -o $(TARGET) $(CXXLIBS) $(CXXFLAGS)

clean:
	rm $(TARGET)
