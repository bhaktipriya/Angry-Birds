CC=g++
CFLAGS=-I.
DEPS = globals.h bird.h speedy.h canon.h block.h

all: main

main: main.cpp glad.c
	g++ -std=c++11 -o main main.cpp glad.c -lGL -lglfw -lftgl -lSOIL -ldl -I/usr/local/include -I/usr/local/include/freetype2 -L/usr/local/lib
clean:
	rm main
