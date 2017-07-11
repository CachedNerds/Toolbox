# flags
CPP_FLAGS = --std=c++1z -c

# file lists
OBJ_FILES = main.o Logger.o Level.o ConsoleSink.o Stringifiable.o Message.o
TEST_OBJ_FILES = TestLevel.o Level.o TestMessage.o TestSink.o TestConvertibleTo.o TestStringifiable.o \
                 Stringifiable.o TestBasicSink.o TestLogger.o
TEST_EXE_FILES = LevelTests ConvertibleToTests StringifiableTests BasicSinkTests LoggerTests

# directories
SINK = sink
CONVERSION = conversion
TESTS = tests
TEST_TYPES = test_types

# Executable Targets
all: $(OBJ_FILES)
	g++ $(OBJ_FILES) -o logger

main.o: main.cpp Message.o ConsoleSink.o Logger.o
	g++ $(CPP_FLAGS) main.cpp

Logger.o: Stringifiable.o $(SINK)/BasicSink.h Level.h Logger.h Logger.cpp
	g++ $(CPP_FLAGS) Logger.cpp

Level.o: Level.h Level.cpp
	g++ $(CPP_FLAGS) Level.cpp

ConsoleSink.o: $(SINK)/BasicSink.h $(SINK)/BasicSink.cpp $(SINK)/ConsoleSink.h $(SINK)/ConsoleSink.cpp
	g++ $(CPP_FLAGS) $(SINK)/ConsoleSink.cpp

Stringifiable.o: $(CONVERSION)/ConvertibleTo.h $(CONVERSION)/Stringifiable.h $(CONVERSION)/Stringifiable.cpp
	g++ $(CPP_FLAGS) $(CONVERSION)/Stringifiable.cpp

Message.o: Stringifiable.o Message.h Message.cpp $(CONVERSION)/ConvertibleTo.h
	g++ $(CPP_FLAGS) Message.cpp

# Tests Targets
TestMessage.o: $(CONVERSION)/ConvertibleTo.h $(TESTS)/$(TEST_TYPES)/TestMessage.h $(TESTS)/$(TEST_TYPES)/TestMessage.cpp
	g++ $(CPP_FLAGS) $(TESTS)/$(TEST_TYPES)/TestMessage.cpp

TestSink.o: $(SINK)/BasicSink.h $(SINK)/BasicSink.cpp $(TESTS)/$(TEST_TYPES)/TestSink.h $(TESTS)/$(TEST_TYPES)/TestSink.cpp
	g++ $(CPP_FLAGS) $(TESTS)/$(TEST_TYPES)/TestSink.cpp

TestLevel.o: Level.o $(TESTS)/Level.cpp
	g++ $(CPP_FLAGS) $(TESTS)/Level.cpp -o TestLevel.o

TestConvertibleTo.o: TestMessage.o $(TESTS)/$(CONVERSION)/ConvertibleTo.cpp
	g++ $(CPP_FLAGS) $(TESTS)/$(CONVERSION)/ConvertibleTo.cpp -o TestConvertibleTo.o

TestStringifiable.o: Stringifiable.o $(CONVERSION)/Stringifiable.h $(CONVERSION)/Stringifiable.cpp $(TESTS)/$(CONVERSION)/Stringifiable.cpp
	g++ $(CPP_FLAGS) $(TESTS)/$(CONVERSION)/Stringifiable.cpp -o TestStringifiable.o

TestBasicSink.o: TestSink.o $(TESTS)/$(SINK)/BasicSink.cpp
	g++ $(CPP_FLAGS) $(TESTS)/$(SINK)/BasicSink.cpp -o TestBasicSink.o

TestLogger.o: TestSink.o TestMessage.o Logger.o Level.o $(TESTS)/Logger.cpp
	g++ $(CPP_FLAGS) $(TESTS)/Logger.cpp -o TestLogger.o

# Command Targets
tests: $(TEST_OBJ_FILES)
	g++ TestLevel.o Level.o -o LevelTests
	g++ TestMessage.o TestConvertibleTo.o -o ConvertibleToTests
	g++ TestStringifiable.o Stringifiable.o -o StringifiableTests
	g++ TestSink.o TestBasicSink.o -o BasicSinkTests
	g++ TestSink.o TestMessage.o Level.o Logger.o TestLogger.o -o LoggerTests

run:
	./logger

run-tests:
	./LevelTests
	./ConvertibleToTests
	./StringifiableTests
	./BasicSinkTests
	./LoggerTests

clean:
	rm *.o $(TESTS)/*.o logger $(TEST_EXE_FILES)
