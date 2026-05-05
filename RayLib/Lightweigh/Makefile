CC = gcc

CFLAGS = -Wall -O2 -std=c99

SRC = lightweigh-pong.c

TARGET = Pong.out

RLSRC = -L./libraylib/linux

ifeq ($(shell uname), Darwin)
        LIBS =  $(RLSRC) -I./libraylib/linux -lraylib -framework CoreVideo -framework IOKit -framework Cocoa -framework OpenGL
else
        LIBS = $(RLSRC) -I./libraylib/linux -lraylib -lm -ldl -lpthread -lrt -lX11
endif

web: SRC = WebLiPong.c
web: RLSRC = -L./libraylib/web
web: TARGET = Pong.html
web: LIBS = -I./libraylib/web -lraylib
web: CFLAGS = -Wall -Os -std=c99 -DPLATFORM_WEB -s USE_GLFW=3 -s ASYNCIFY
web: CC = emcc


web:
	@echo "Building $(SRC) for web..."
	$(CC) $(SRC) -o $(TARGET) $(RLSRC) $(LIBS) $(CFLAGS) 
	@echo "Executable: $(TARGET)"

unix:
	@echo "Building $(SRC)..."
	$(CC) $(SRC) -o $(TARGET) $(LIBS) $(CFLAGS) 
	@echo "Executable: $(TARGET)" 

clean:
	rm -f Pong.*
