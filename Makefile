# -*- Makefile -*-

all: frequency

frequency: main_driver.o Trie.o
	gcc -Wall -o frequency main_driver.o Trie.o

main_driver.o: main_driver.c Trie.h
	gcc -Wall -c main_driver.c

Trie.o: Trie.c Trie.h
	gcc -Wall -fPIC -c Trie.c

.PHONY: all clean

clean:
	rm -f *.o frequency
