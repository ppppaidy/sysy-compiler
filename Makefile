# Makefile
# compile the compiler

CC = g++

LEX = flex

YACC = bison

CFLAGS = -Wno-register -O2 -lm -std=c++17

OBJS = main.o parser.tab.o lex.yy.o eeyoregen.o tiggergen.o

compiler: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o compiler

main.o: main.cpp globals.h scan.h globals.h nodedef.h parse.h eeyoregen.h tiggergen.h
	$(CC) $(CFLAGS) -c main.cpp

lex.yy.o: lexer.l globals.h scan.h parser.tab.hpp
	-$(LEX) -o lex.yy.cpp lexer.l
	-$(CC) $(CFLAGS) -c lex.yy.cpp

parser.tab.o: parser.y globals.h scan.h nodedef.h parse.h
	-$(YACC) -d -o parser.tab.cpp parser.y
	-$(CC) $(CFLAGS) -c parser.tab.cpp

eeyoregen.o: eeyoregen.cpp eeyoregen.h
	$(CC) $(CFLAGS) -c eeyoregen.cpp

tiggergen.o: tiggergen.cpp tiggergen.h
	$(CC) $(CFLAGS) -c tiggergen.cpp

eeyoregen.h: nodedef.h

parse.h: nodedef.h

clean:
	-rm -rf compiler
	-rm -rf $(OBJS)
	-rm -rf lex.yy.cpp
	-rm -rf parser.tab.cpp
	-rm -rf parser.tab.hpp