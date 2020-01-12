

all: main.o trie.o frequency
frequency: trie.o main.o
		gcc -Wall -g -fPIC -o frequency trie.o main.o -lm
trie.o: trie.c trie.h
		gcc -Wall -g -fPIC -c trie.c
main.o: main.c trie.c trie.h
		gcc -Wall -g -fPIC -c main.c

.PHONY: clean all

clean:rm -f *.o frequency