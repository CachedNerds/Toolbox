# Building with Tup
## Dependencies
The build system that we use is called _tup_ and it is required in order to build the Toolbox.
Goto [Tup Home](http://gittup.org/tup/) to follow the instructions on how to install tup.

## Building
1. clone the Toolbox repository.
2. enter the libs directory.
3. run the command `tup`

This will tell the _tup_ build system to orchestrate the building of the whole Toolbox.

If you only want to build specific projects within the Toolbox simple pass a list of project names to the tup command, e.g. `tup project1 project2 project3`.

## Setting up a new project
### Directory Structure
Every project within the Toolbox follows a predefined directory structure that is necessary in order for the project to build correctly.

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
    - Project A
      - header files
    - Project B
      - etc
    - Project C
      - etc

The Toolbox directory structure has two major internal sections `Toolbox` and `libs`.

#### Toolbox
The `Toolbox` directory is where all publicly accessable headers are located and this facilitates uniform library inclusion.  In order to include anything from the Toolbox you would say `#include <Toolbox/Project/project.h>`.

- Toolbox
  - Project A
    - header files
  - Project B
    - etc
  - Project C
    - etc

#### libs
The `libs` directory has three different types of subdirectories: `src`, `test`, and `build`.
- src: contains all cpp source files organized in any way the project creators see fit.
- test: contains all of the test files for a project.
- build: holds all build artifacts such as object files, test executables, and libraries.

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

This file structure must exist in order for the build process to work successfully.
Note: the _tup_ build system will automatically create the build directories if they don't already exist.

### Tup
- Pending
