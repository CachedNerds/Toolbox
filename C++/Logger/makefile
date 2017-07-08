CPP_FLAGS = --std=c++1z -c
ADDITIONAL_FLAGS = -DBOOST_SYSTEM_NO_DEPRECATED -I ~/boost_1_64_0
LINKER_FLAGS = -lboost_system
OBJ_FILES = main.o Logger.o Level.o ConsoleSink.o Stringifiable.o Message.o
TEST_OBJ_FILES = TestLevel.o Level.o TestStringifiable.o Stringifiable.o TestVariantVisitor.o TestBasicSink.o
SINK = sink
CONVERSION = conversion
TESTS = tests

# Executable Targets
all: $(OBJ_FILES)
	g++ $(LINKER_FLAGS) $(OBJ_FILES) -o logger

main.o: main.cpp Message.o ConsoleSink.o Logger.o
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) main.cpp

Logger.o: Stringifiable.o $(SINK)/BasicSink.h Level.h Logger.h Logger.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Logger.cpp

Level.o: Level.h Level.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Level.cpp

ConsoleSink.o: $(SINK)/BasicSink.h $(SINK)/BasicSink.cpp $(SINK)/ConsoleSink.h $(SINK)/ConsoleSink.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(SINK)/ConsoleSink.cpp

Stringifiable.o: $(CONVERSION)/ConvertibleTo.h $(CONVERSION)/Stringifiable.h $(CONVERSION)/Stringifiable.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(CONVERSION)/Stringifiable.cpp

Message.o: Stringifiable.o Message.h Message.cpp $(CONVERSION)/ConvertibleTo.h
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) Message.cpp

# Tests Targets
TestLevel.o: Level.o $(TESTS)/Level.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(TESTS)/Level.cpp -o TestLevel.o

TestStringifiable.o: Stringifiable.o $(CONVERSION)/Stringifiable.h $(CONVERSION)/Stringifiable.cpp $(TESTS)/$(CONVERSION)/Stringifiable.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(TESTS)/$(CONVERSION)/Stringifiable.cpp -o TestStringifiable.o

TestVariantVisitor.o: $(CONVERSION)/VariantVisitor.h $(CONVERSION)/VariantVisitor.cpp $(TESTS)/$(CONVERSION)/VariantVisitor.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(TESTS)/$(CONVERSION)/VariantVisitor.cpp -o TestVariantVisitor.o

TestBasicSink.o: $(SINK)/BasicSink.h $(SINK)/BasicSink.cpp $(TESTS)/$(SINK)/BasicSink.cpp
	g++ $(CPP_FLAGS) $(ADDITIONAL_FLAGS) $(TESTS)/$(SINK)/BasicSink.cpp -o TestBasicSink.o

# Command Targets
tests: $(TEST_OBJ_FILES)
	g++ $(LINKER_FLAGS) TestLevel.o Level.o -o LevelTests
	g++ $(LINKER_FLAGS) TestStringifiable.o Stringifiable.o -o StringifiableTests
	g++ $(LINKER_FLAGS) TestVariantVisitor.o -o VariantVisitorTests
	g++ $(LINKER_FLAGS) TestBasicSink.o -o BasicSinkTests

run:
	./logger

run-tests:
	./LevelTests
	./StringifiableTests
	./VariantVisitorTests
	./BasicSinkTests

clean:
	rm *.o $(TESTS)/*.o logger test LevelTests StringifiableTests VariantVisitorTests BasicSinkTests