CFLAGS += --std=c++17 -c
OUTFILE = "env"

all: main.o Development.o Production.o
	g++ Development.o Production.o main.o -o $(OUTFILE)

Development.o: Environment.h Development.h Development.cpp
	g++ $(CFLAGS) Development.cpp

Production.o: Environment.h Production.h Production.cpp
	g++ $(CFLAGS) Production.cpp

main.o: main.cpp Production.o Development.o
	g++ $(CFLAGS) main.cpp

clean:
	rm *.o env
