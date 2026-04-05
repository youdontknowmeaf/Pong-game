CC = gcc
CFLAGS = -Wall -O2 -std=c99

SRC = lightweigh-pong.c
TARGET = Pong

LIBS = -lraylib -lm -ldl -lpthread -lrt -lX11 -lGL

all:
	@echo "This is lightweigh release, it contains less stuff than normal release."
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LIBS)

clean:
	rm -f Pong
