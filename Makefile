CPP         = g++
CPP_FLAGS   = -std=c++11 -O3
LIBS        = -lm
CPP_OBJ     =  RandomWalk.o ContinuumRandomWalk.o GeometricRandomWalk.o ContinuumGeometricRandomWalk.o
CPP_SRC     = RandomWalk.cpp ContinuumRandomWalk.cpp GeometricRandomWalk.cpp ContinuumGeometricRandomWalk.cpp

all:
	make objects
	make geometricrandomwalk
	make randomwalk
	make continuumrandomwalk
	make continuumgeometricrandomwalk

continuumgeometricrandomwalk:
	cd src && $(CPP) $(CFLAGS) $(CLIBS) -o ../bin/continuumgeometricrandomwalk ContinuumGeometricRandomWalk.o

geometricrandomwalk:
	cd src && $(CPP) $(CFLAGS) $(CLIBS) -o ../bin/geometricrandomwalk GeometricRandomWalk.o

randomwalk: 
	cd src && $(CPP) $(CFLAGS) $(LIBS) -o ../bin/randomwalk RandomWalk.o

continuumrandomwalk:
	cd src && $(CPP) $(CFLAGS) $(CLIBS) -o ../bin/continuumrandomwalk ContinuumRandomWalk.o

objects:
	cd ./src && $(CPP) $(CPP_FLAGS) -c $(CPP_SRC)

clean:
	rm ./bin/* *.o *~ src/*.o src/*~ include/*~ plotting/*~ 
