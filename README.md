# C++ Test Resolution

Welcome to the CINQ hiring test for C++ developers resolution.

There are ten challenges solved, each one with its own constraints and test cases.

## Dependencies

* Bash
* CMake
* Diff
* A C++ compiler (like G++ or clang) with support to C++11 (enforced in CMake file).

As optional dependency, if doxygen is present, documentation can be generated.

## Tested Environment
Debian 4.19.13-1 x86_64 GNU/Linux
g++ (Debian 8.2.0-14) 8.2.0

## Tests

Every test has passed with success.

While modifying the code, you can check for errors (in a simplified way) for all tests at once (from /build/ dir) doing:
```
make && for clg in $(ls -d ../challenges/*/ | cut -d "/" -f3); do echo "ctest -R $clg -V"; ctest -R $clg > /dev/null; done;
```

## Building and running the test cases

Everything in this test is automated using CMake.
You can create a shadow build folder or build it in the root folder (but this is not recommended).
Here we are going to assume you are in the root folder.

#### Creating build folder and Running CMake:

```
$ mkdir build
$ cd build
$ cmake ..
```

#### Building the project and documentation:

```
$ make all
$ make doc # optional
```

#### Running the tests cases:

```
$ ctest .
```

#### Running a specific test case (verbose):

```
$ ctest -R <test> -V
```

CTest will show you which one of the test cases failed. You are free to look at the tests cases to better understand what is required to make it pass. Don't forget to build the code before running the tests.
