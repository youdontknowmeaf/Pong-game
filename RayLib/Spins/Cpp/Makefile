CXX = g++
CXXFLAGS = -Wall -O2
CXXLIBS = -lraylib -lm -ldl -lpthread -lrt -lX11
TARGET = Pong
SRC = main.cpp
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXLIBS) $(CXXFLAGS)

clean:
	rm -f $(TARGET)
