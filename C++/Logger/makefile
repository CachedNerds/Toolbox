CPP_FLAGS = --std=c++1z -c
ADDITIONAL_FLAGS = -DBOOST_SYSTEM_NO_DEPRECATED -I ~/boost_1_64_0
LINKER_FLAGS = -lboost_system
OBJ_FILES = main.o Severity.o Logger.o StdOutSink.o
SINKS = sinks
SYNC = sinks/sync

all: $(OBJ_FILES)
	g++ $(LINKER_FLAGS) $(OBJ_FILES) -o logger

Logger.o: Logger.h Logger.cpp StdOutSink.o
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Logger.cpp

main.o: main.cpp Logger.o
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) main.cpp

Severity.o: Severity.h Severity.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Severity.cpp

StdOutSink.o: $(SINKS)/Sink.h $(SYNC)/StdOutSink.h $(SYNC)/StdOutSink.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(SYNC)/StdOutSink.cpp

clean:
	rm *.o logger