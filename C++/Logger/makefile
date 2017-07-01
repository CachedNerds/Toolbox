CPP_FLAGS = --std=c++1z -c
ADDITIONAL_FLAGS = -DBOOST_SYSTEM_NO_DEPRECATED -I ~/boost_1_64_0
LINKER_FLAGS = -lboost_system
OBJ_FILES = main.o Severity.o Message.o ConsoleSink.o
SINKS = sinks
SYNC = sinks/sync

all: $(OBJ_FILES)
	g++ $(LINKER_FLAGS) $(OBJ_FILES) -o logger

main.o: main.cpp Message.o ConsoleSink.o
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) main.cpp

Message.o: $(SINKS)/Message.h $(SINKS)/Message.cpp $(SINKS)/Output.h
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(SINKS)/Message.cpp

Severity.o: Severity.h Severity.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Severity.cpp

ConsoleSink.o: $(SYNC)/ConsoleSink.h $(SYNC)/ConsoleSink.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(SYNC)/ConsoleSink.cpp

clean:
	rm *.o logger