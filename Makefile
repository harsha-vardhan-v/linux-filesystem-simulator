CC := gcc
CFLAGS := -wall

fileSystem: src/tree.h bin/cli_tools.o main.c
	$(CC) main.c bin/cli_tools.o -o bin/fileSystem

bin/cli_tools.o: src/cli_tools.h src/cli_tools.c
	$(CC) -c src/cli_tools.c -o bin/cli_tools.o

clean:
	rm -rf bin/*
