CPP_FLAGS = --std=c++1z -c
ADDITIONAL_FLAGS = -DBOOST_SYSTEM_NO_DEPRECATED -I ~/boost_1_64_0
LINKER_FLAGS = -lboost_system
OBJ_FILES = main.o Severity.o Logger.o Sink.o ConsoleSink.o
SINKS = sinks
SYNC = sinks/sync

all: $(OBJ_FILES)
	g++ $(LINKER_FLAGS) $(OBJ_FILES) -o logger

Logger.o: ConsoleSink.o Sink.o Logger.h Logger.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Logger.cpp

Sink.o: $(SINKS)/Sink.h $(SINKS)/Sink.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(SINKS)/Sink.cpp

main.o: main.cpp Logger.o
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) main.cpp

Severity.o: Severity.h Severity.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Severity.cpp

ConsoleSink.o: Sink.o $(SYNC)/ConsoleSink.h $(SYNC)/ConsoleSink.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(SYNC)/ConsoleSink.cpp

clean:
	rm *.o logger