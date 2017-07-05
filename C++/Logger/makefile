CPP_FLAGS = --std=c++1z -c
ADDITIONAL_FLAGS = -DBOOST_SYSTEM_NO_DEPRECATED -I ~/boost_1_64_0
LINKER_FLAGS = -lboost_system
OBJ_FILES = main.o Logger.o Level.o ConsoleSink.o Stringifiable.o Message.o
TEST_OBJ_FILES = TestLevel.o Level.o TestStringifiable.o Stringifiable.o
SINKS = sinks
OUTPUTS = outputs
TESTS = tests

# Executable Targets
all: $(OBJ_FILES)
	g++ $(LINKER_FLAGS) $(OBJ_FILES) -o logger

main.o: main.cpp Message.o ConsoleSink.o Logger.o
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) main.cpp

Logger.o: Stringifiable.o $(SINKS)/BasicSink.h Level.h Logger.h Logger.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Logger.cpp

Level.o: Level.h Level.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Level.cpp

ConsoleSink.o: $(SINKS)/ConsoleSink.h $(SINKS)/ConsoleSink.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(SINKS)/ConsoleSink.cpp

Stringifiable.o: $(OUTPUTS)/Outputable.h $(OUTPUTS)/Stringifiable.h $(OUTPUTS)/Stringifiable.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(OUTPUTS)/Stringifiable.cpp

Message.o: Stringifiable.o $(OUTPUTS)/Message.h $(OUTPUTS)/Message.cpp $(OUTPUTS)/Outputable.h
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(OUTPUTS)/Message.cpp

# Tests Targets
TestLevel.o: Level.o $(TESTS)/Level.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(TESTS)/Level.cpp -o TestLevel.o

TestStringifiable.o: Stringifiable.o $(TESTS)/$(OUTPUTS)/Stringifiable.*
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(TESTS)/$(OUTPUTS)/Stringifiable.cpp -o TestStringifiable.o

# Command Targets
tests: $(TEST_OBJ_FILES)
	g++ $(LINKER_FLAGS) TestLevel.o Level.o -o LevelTests
	g++ $(LINKER_FLAGS) TestStringifiable.o Stringifiable.o -o StringifiableTests

run:
	./logger

run-tests:
	./LevelTests
	./StringifiableTests

clean:
	rm *.o $(TESTS)/*.o logger test