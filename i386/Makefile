CC = gcc
CFLAGS = -Wall -O2 -m32

SRC = ../x86_64/main.c
TARGET = Pong

LIBS = -lraylib -lm -ldl -lpthread -lrt -lX11 -lGL

all:
	@echo "I do not guarantee that it will work. Didn't work for me at all. But tinker if you want."
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) -I. -L. $(LIBS)
	@file Pong

clean:
	rm -f Pong
