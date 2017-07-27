# Building with Tup
## Dependencies
The build system that we use is called _tup_ and is required to build the Toolbox.
Visit [Tup Home](http://gittup.org/tup/) for instructions on how to install tup.

## Building
**1.** Clone the repository.
```
$ git clone https://github.com/CachedNerds/Toolbox.git
```
**2.** Navigate to the libs directory.
```
$ cd Toolbox/libs
```
**3.** Build Toolbox
  + To build all projects in Toolbox
    ```
    $ tup
    ```
  + To build a specific project or a set of specific projects
    ```
    $ tup projectA projectB
    ```

## Project structure
#### Toolbox directory structure
- Toolbox
  - libs
    - Project A
      - build
        - build artifacts
      - src
        - source files
      - test
        - build
          - build artifacts
        - src
          - source files
    - Project B
      - etc
    - Project C
      - etc
  - Toolbox
      -  - Project A
      - header files
    - Project B
      - etc
    - Project C
      - etc

Every project within the Toolbox follows a predefined directory structure that is necessary for the project to build correctly.

The Toolbox directory structure has two major internal sections `Toolbox` and `libs`.

### Toolbox
- Toolbox
  - Project A
    - header files
  - Project B
    - etc
  - Project C
    - etc

The `Toolbox` directory is where all publicly accessable headers are located and this facilitates uniform library inclusion.  In order to include anything from the Toolbox you would say `#include <Toolbox/Project/header.h>`.

### libs
- libs
  - Project A
    - build
      - build artifacts
    - src
      - source files
    - test
      - build
        - build artifacts
      - src
        - source files
  - Project B
    - etc
  - Project C
    - etc
 
The `libs` directory has three different types of subdirectories: `src`, `test`, and `build`.
- `src`: contains all cpp source files organized in any way the project creators see fit.
- `test`: contains all of the test files for a project, must have an interior `build` and `src` directory.
- `build`: holds all build artifacts such as object files, test executables, and libraries.

This file structure must exist in order for the build process to work successfully.
Note: the _tup_ build system will automatically create the build directories if they don't already exist.

## Project build setup
There are several files that play an important role in configuring your project to build.

### Tupfile.ini
The `Tupfile.ini` is an empty file that allows tup to build on a new machine without the user running the `tup init` command in the correct location.  This file must simply exist within the `Toolbox/libs` directory.

### Tuprules.tup (explain more of what it does)
The `Tuprules.tup` file defines common configuration variables and build macros such as `!compile`, `!archive`, and `!link`.  

#### Supported variables
Some of these variables can be overriden with project specific values within a projects local Tupfile.

##### Nonoverridable variables
- `EXTENSION`
  - defines the type of library that is going to be produced, this variable is determined based off the values for `STATIC` and `SHARED` from the `$(TUP_PLATFORM).tup` file and the `LIB_TYPE` variable from the `config.tup` file.
  - default: pending
- `PROJECT_LIB`
  - defines the executable name of the produced library, this variable is determined using the `PROJECT` variable defined in the `config.tup` file and the `EXTENSION` variable.
  - default: pending

##### Overridable variables
- `CC`
  - defines the compiler
  - default: `g++`
- `CFLAGS`
  - define the flags passed to the compiler
  - default: `-g -std=c++1z -c -I ../../` (../../ allows `#include <Toolbox/Project/header.h>`)
- `SOURCE`
  - defines the location of the source files
  - default: `src`
- `SOURCE_OUT`
  - defines the location where source build artifacts are output
  - default: `build`
- `SOURCE_FILES`
  - defines the set of source files to compile
  - default: `$(SOURCE)/*.cpp`
- `SOURCE_OBJ_FILES`
  - defines the set of source object files created by compilation
  - default: `$(SOURCE_OUT)/*.o`
- `TEST`
  - defines the location of the test files
  - default: `src`
- `TEST_OUT`
  - defines the location where test build artifacts are output
  - default: `$(TEST)/build`
- `TEST_FILES`
  - defines the set of test files to compile
  - default: `$(TEST)/$(SOURCE)/*.cpp`
- `TEST_OBJ_FILES`
  - defines the set of test object files created by compilation
  - default: `$(TEST_OUT)/*.o`

##### Macros
- `!compile`
  - the `!compile` macro takes user defined inputs, compiles them using the `CC` and `CFLAGS` variables, and names the output based on the user defined output name
  - example: `object.cpp |> !compile |> object.o`
- `!archive`
  - the `!archive` macro takes a set of object files, archives them, and names the output based on the user defined output name
  - example: `objectA.o objectB.o |> !archive |> objects.a`
- `!link`
  - the `!link` macro takes a set of object files or libraries, links them using the `CC` variable, and names the output based on the user defined output name
  - example: `objectA.o objectB.o libaryA.a |> !link |> exename`

### $(TUP_PLATFORM).tup
The `$(TUP_PLATFORM).tup` file (e.g. linux.tup) defines any platform specific variables needed to build on the linux platform.  This file is then included within the `Tuprules.tup` file and the build system will act accordingly.

#### Supported variables
There are only a handful of variable definitions that the `Tuprules.tup` file is expecting the `$(TUP_PLATFORM).tup` file to define, `STATIC` and `SHARED`.  These define the file extensions for static and shared libraries on that platform.

- `STATIC`
  - linux/macosx
    - example: `STATIC = a`
  - win32/win64
    - example: `STATIC = lib`
- `SHARED`
  - linux/macosx
    - example: `SHARED = so`
  - win32/win64
    - example: `SHARED = dll`

### config.tup
The `config.tup` file is defined within each project and supplies project specific configurations for the build process.

#### Supported variables
There are only a handful of variable definitions that the `Tuprules.tup` file is expecting the `config.tup` to define, `PROJECT` and `LIB_TYPE`.

- `PROJECT`
  - defines the name of the project that _tup_ will use to name the library and test executable.
  - example: `PROJECT = Conversion`
- `LIB_TYPE`
  - define whether you wish to build the project as a static library, shared library or both.
  - lib types: static, shared, both
  - example: `LIB_TYPE = static`

### Tupfile
The project specific `Tupfile` is where every project includes its `config.tup` file and the shared `Tuprules.tup` file, override the variables defined within `Tuprules.tup`, define any project specific variables, and defines the projects build steps.

#### Tupfile sections
##### includes
There is one requirement for how Toolbox Tupfiles should be order.  The top of your `Tupfile` you must include the projects `config.tup` file followed by the `include_rules` statement.  This is extremely important because the `Tuprules.tup` file is expecting the values within the `config.tup` file to be defined.

So the top of each projects `Tupfile` will look like this:
```
include config.tup
include_rules
```

#### Override variables
After the `include_rules` statement is each projects opportunity to override any overridable flags defined within the `Tuprules.tup` file.

#### Project specific variables
Next you can define project specific variables that will be used within the build rules, these can be anything.

#### Build rules
There are four steps to building a Toolbox project each of which have three components: `input`, `command`, and `output`.

##### Compile Source
The first step is to compile the source files of the project.
- input: the source files (`SOURCE_FILES`)
- command: the `!compile` macro
- output: the source output location (`SOURCE_OUT`)

The `Tuprules.tup` file provides the `!compile` macro as well as default values for the `SOURCE_FILES` and `SOURCE_OUT` variables that can be used to define the compile source rule.
- default Compile Source rule: `: foreach $(SOURCE_FILES) |> !compile |> $(SOURCE_OUT)/%B.o`

##### Archive Source
The next step is to archive the projects object files into a library.  There are three components to archiving a project's source: the source object files, the `!archive` macro, and the output location.  The `Tuprules.tup` file provides the `!archive` macro as well as default values for the `SOURCE_OBJ_FILES` and `SOURCE_OUT`

##### Compile Tests
The first step is to compile the test source files of the project.
- input: the test source files (`TEST_FILES`)
- command: the `!compile` macro
- output: the source output location (`TEST_OUT`)

The `Tuprules.tup` file provides the `!compile` macro as well as default values for the `TEST_FILES` and `TEST_OUT` variables that can be used to define the compile source rule.
- default Compile Tests rule: `: foreach $(TEST_FILES) |> !compile |> $(TEST_OUT)/%B.o`

##### Create Test Executable

###### Explain use of project groups
