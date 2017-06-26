CFLAGS += --std=c++17 -c
OUTFILE = "env"

all: main.o Dev.o Prod.o
	g++ Dev.o Prod.o main.o -o $(OUTFILE)

Dev.o: Env.h Dev.h Dev.cpp
	g++ $(CFLAGS) Dev.cpp

Prod.o: Env.h Prod.h Prod.cpp
	g++ $(CFLAGS) Prod.cpp

main.o: main.cpp Prod.o Dev.o
	g++ $(CFLAGS) main.cpp

clean:
	rm *.o env
