
fileSystem: src/tree.h bin/cli_tools.o main.c
	gcc main.c bin/cli_tools.o -o bin/fileSystem

bin/cli_tools.o: src/cli_tools.h src/cli_tools.c
	gcc -c src/cli_tools.c -o bin/cli_tools.o

clean:
	rm fileSystem