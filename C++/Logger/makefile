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

# compiler
CC = g++

# Executable Targets
all: $(OBJ_FILES)
	$(CC) $(OBJ_FILES) -o logger

main.o: main.cpp Message.o ConsoleSink.o Logger.o
	$(CC) $(CPP_FLAGS) main.cpp

Logger.o: Stringifiable.o $(SINK)/BasicSink.h Level.h Logger.h Logger.cpp
	$(CC) $(CPP_FLAGS) Logger.cpp

Level.o: Level.h Level.cpp
	$(CC) $(CPP_FLAGS) Level.cpp

ConsoleSink.o: $(SINK)/BasicSink.h $(SINK)/BasicSink.cpp $(SINK)/ConsoleSink.h $(SINK)/ConsoleSink.cpp
	$(CC) $(CPP_FLAGS) $(SINK)/ConsoleSink.cpp

Stringifiable.o: $(CONVERSION)/ConvertibleTo.h $(CONVERSION)/Stringifiable.h $(CONVERSION)/Stringifiable.cpp
	$(CC) $(CPP_FLAGS) $(CONVERSION)/Stringifiable.cpp

Message.o: Stringifiable.o Message.h Message.cpp $(CONVERSION)/ConvertibleTo.h
	$(CC) $(CPP_FLAGS) Message.cpp

# Tests Targets
TestMessage.o: $(CONVERSION)/ConvertibleTo.h $(TESTS)/$(TEST_TYPES)/TestMessage.h $(TESTS)/$(TEST_TYPES)/TestMessage.cpp
	$(CC) $(CPP_FLAGS) $(TESTS)/$(TEST_TYPES)/TestMessage.cpp

TestSink.o: $(SINK)/BasicSink.h $(SINK)/BasicSink.cpp $(TESTS)/$(TEST_TYPES)/TestSink.h $(TESTS)/$(TEST_TYPES)/TestSink.cpp
	$(CC) $(CPP_FLAGS) $(TESTS)/$(TEST_TYPES)/TestSink.cpp

TestLevel.o: Level.o $(TESTS)/Level.cpp
	$(CC) $(CPP_FLAGS) $(TESTS)/Level.cpp -o TestLevel.o

TestConvertibleTo.o: TestMessage.o $(TESTS)/$(CONVERSION)/ConvertibleTo.cpp
	$(CC) $(CPP_FLAGS) $(TESTS)/$(CONVERSION)/ConvertibleTo.cpp -o TestConvertibleTo.o

TestStringifiable.o: Stringifiable.o $(CONVERSION)/Stringifiable.h $(CONVERSION)/Stringifiable.cpp $(TESTS)/$(CONVERSION)/Stringifiable.cpp
	$(CC) $(CPP_FLAGS) $(TESTS)/$(CONVERSION)/Stringifiable.cpp -o TestStringifiable.o

TestBasicSink.o: TestSink.o $(TESTS)/$(SINK)/BasicSink.cpp
	$(CC) $(CPP_FLAGS) $(TESTS)/$(SINK)/BasicSink.cpp -o TestBasicSink.o

TestLogger.o: TestSink.o TestMessage.o Logger.o Level.o $(TESTS)/Logger.cpp
	$(CC) $(CPP_FLAGS) $(TESTS)/Logger.cpp -o TestLogger.o

# Command Targets
tests: $(TEST_OBJ_FILES)
	$(CC) TestLevel.o Level.o -o LevelTests
	$(CC) TestMessage.o TestConvertibleTo.o -o ConvertibleToTests
	$(CC) TestStringifiable.o Stringifiable.o -o StringifiableTests
	$(CC) TestSink.o TestBasicSink.o -o BasicSinkTests
	$(CC) TestSink.o TestMessage.o Level.o Logger.o TestLogger.o -o LoggerTests

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
