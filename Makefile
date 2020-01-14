# -*- Makefile -*-

all: Trie main_driver

Trie: main_driver.o libTrie.a
	gcc -Wall -o Trie main_driver.o libTrie.a
	
libTrie.a: Trie.o
	ar -rcs libTrie.a Trie.o

main_driver.o: main_driver.c Trie.h
	gcc -Wall -c main_driver.c

Trie.o: Trie.c Trie.h
	gcc -Wall -fPIC -c Trie.c

.PHONY: all clean

clean:
	rm -f *.o *.a Trie
