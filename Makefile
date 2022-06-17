CXX = clang++

CFLAGS = -Wall -g
LFLAGS =  -lsfml-graphics -lsfml-window -lsfml-system
OBJECTS = main.o BoundingBox.o GameObject.o

./bin/game: $(OBJECTS)
	$(CXX) $(OBJECTS) -o ./bin/game $(LFLAGS)

clean:
	rm *.o ./bin/*
