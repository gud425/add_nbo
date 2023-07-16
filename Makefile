#Makefile
all: add_nbo thousand.bin five-hundred.bin

add_nbo: main.cpp
	g++ -o add-nbo main.cpp
	
clean:
	rm -f add-nbo
