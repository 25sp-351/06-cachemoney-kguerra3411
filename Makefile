CC = clang
CFLAGS = -Wall 

all: output

output: main.o num_to_words.o cache.o
	$(CC) $(CFLAGS) -o output main.o num_to_words.o cache.o

main.o: main.c num_to_words.h cache.h
	$(CC) $(CFLAGS) -c main.c

num_to_words.o: num_to_words.c num_to_words.h cache.h
	$(CC) $(CFLAGS) -c num_to_words.c

cache.o: cache.c cache.h
	$(CC) $(CFLAGS) -c cache.c

clean:
	rm -f output main.o num_to_words.o cache.o