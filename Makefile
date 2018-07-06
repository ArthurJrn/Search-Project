CC = g++

all: main

main: main.o 
	$(CC) main.cpp sound.cpp dico.cpp soundex.cpp group.cpp bgroup.cpp anex.cpp word.cpp
	./a.out	  

clean:
	rm main *.o*

