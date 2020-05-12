CC = g++
OBFLAGS = -g -O0 -c -Wall -I

debug: dmain.o dquicksort.o
	@echo "Linking objects and compiling executable with debugging symbols..."
	$(CC) -g -Wall build/main.o build/quicksort.o -o bin/main.out
	@echo "Finished linking and compiling main.out"

dmain.o:
	@echo "Compiling main with debugging symbols..."
	$(CC) -g $(OBFLAGS) include/ src/main.cpp -o build/main.o
	@echo "Finished compiling main"
	
dquicksort.o:
	@echo "Compiling quicksort debugging symbols..."
	$(CC) -g $(OBFLAGS) include/ src/quicksort.cpp -o build/quicksort.o
	@echo "Finished compiling quicksort"
 
clean:
	@echo "Removing all contents of build directory..."
	rm -rf build/*
	@echo "Removed"
