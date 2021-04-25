# Makefile
# compile the compiler

CC = g++

CFLAGS = -Wno-register -O2 -lm -std=c++17

OBJS = main.o

compiler: $(OBJS)
	-$(CC) $(CFLAGS) $(OBJS) -o compiler
	-rm -rf $(OBJS)

main.o: main.cpp globals.h
	$(CC) $(CFLAGS) -c main.cpp

clean:
	-rm -rf compiler
	-rm -rf $(OBJS)