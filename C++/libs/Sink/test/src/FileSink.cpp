#include <Toolbox/catch.hpp>

#include <Toolbox/Sink/FileSink.h>

using namespace Toolbox::Sink;

TEST_CASE ("Write to a FileSink")
{
  std::string filename = "test.txt";
  FileSink fileSink (filename);
  fileSink << "test";

  std::remove (filename.c_str ());
}

TEST_CASE ("isReady")
{
  std::string filename = "test.txt";
  FileSink fileSink (filename);

  REQUIRE (fileSink.isReady ());

  std::remove (filename.c_str ());
}

TEST_CASE ("changeFile")
{
  std::string filename = "test.txt";
  FileSink fileSink (filename);
  fileSink << "test";

  std::string newFilename = "test2.txt";
  REQUIRE (fileSink.changeFile (newFilename));
  fileSink << "test2";

  std::remove (filename.c_str ());
  std::remove (newFilename.c_str ());
}