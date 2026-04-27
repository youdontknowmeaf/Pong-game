CC = gcc
CFLAGS = -Wall -O2 -std=c99

SRC = lightweigh-pong.c
TARGET = Pong
ifeq ($(shell uname), Darwin)
    LIBS = -L./libraylib/raylib -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL
else
    LIBS = -L./libraylib/raylib -lraylib -lm -ldl -lpthread -lrt -lX11
endif

all:
	@echo "This is lightweigh release, it contains less stuff than normal release."
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f Pong
