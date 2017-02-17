CPP         = g++
CPP_FLAGS   = -std=c++11 -O3
LIBS        = -lm
CPP_OBJ     =  RandomWalk.o ContinuumRandomWalk.o
CPP_SRC     = RandomWalk.cpp ContinuumRandomWalk.cpp

all:
	make objects

randomwalk: 
	make objects
	cd src && $(CPP) $(CFLAGS) $(LIBS) -o ../bin/randomwalk RandomWalk.o

continuumrandomwalk:
	make objects
	cd src && $(CPP) $(CFLAGS) $(CLIBS) -o ../bin/continuumrandomwalk ContinuumRandomWalk.o

objects:
	cd ./src && $(CPP) $(CPP_FLAGS) -c $(CPP_SRC)

clean:
	rm ./bin/* *.o *~ src/*.o src/*~ include/*~ plotting/*~ 
