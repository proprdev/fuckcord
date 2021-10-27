CFLAGS = -O2 -lcurl
FILES = $(wildcard src/*.cpp)
CC = clang++

main: $(FILES)
	$(CC) $(CFLAGS) $(FILES) -o main



.PHONY: all main clean