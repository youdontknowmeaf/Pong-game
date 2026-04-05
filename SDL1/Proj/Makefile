CXX = gcc
CXXFLAGS = -Wall -O2
CXXLIBS = `sdl-config --cflags --libs` 
TARGET = Pong
SOURCE = main.c
$(TARGET): $(SOURCE)
	$(CXX) $(SOURCE) -o $(TARGET) $(CXXLIBS) $(CXXFLAGS)

clean:
	rm $(TARGET)
