CPPFLAGS = --std=c++1z -c
ADDITIONAL_FLAGS = -DBOOST_SYSTEM_NO_DEPRECATED -I ~/boost_1_64_0
LINKER_FLAGS = -lboost_system

all: main.o Severity.o Logger.o
	g++ $(LINKER_FLAGS) Logger.o Severity.o main.o -o logger

Logger.o: Logger.h Logger.cpp
	g++ $(CPPFLAGS) $(ADDITIONAL_FLAGS) Logger.cpp

main.o: main.cpp Logger.o
	g++ $(CPPFLAGS) $(ADDITIONAL_FLAGS) main.cpp

Severity.o: Severity.h Severity.cpp
	g++ $(CPPFLAGS) $(ADDITIONAL_FLAGS) Severity.cpp

clean:
	rm *.o logger