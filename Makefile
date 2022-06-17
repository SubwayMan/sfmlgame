CC = clang++

CFLAGS = -Wall -g
LFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system

./bin/game: main.o
	$(CC) main.o -o ./bin/game $(LFLAGS)

main.o: main.cpp GameObject.h
	$(CC) -c main.cpp $(CFLAGS)

clean:
	rm *.o ./bin/*
