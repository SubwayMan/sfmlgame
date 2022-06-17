CXX = clang++

CFLAGS = -Wall -g
LFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = main.o BoundingBox.o GameObject.o Player.o

./bin/game: $(OBJECTS)
	$(CXX) $(OBJECTS) -o ./bin/game $(LFLAGS)

GameObject.o: GameObject.h

BoundingBox.o: BoundingBox.h

Player.o: Player.h

clean:
	rm *.o ./bin/*
