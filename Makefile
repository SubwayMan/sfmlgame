CC = clang++

CFLAGS = -Wall -g
LFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system

output: main.o
	$(CC) main.o -o ./bin/game $(LFLAGS)

main.o: main.cpp
	$(CC) -c main.cpp $(CFLAGS)

clean:
	rm *.o ./bin/*
