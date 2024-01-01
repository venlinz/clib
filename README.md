# CLIB
### My own custom C library for my programming needs
this library contains utility functions to ease programming
in C, this was the goal.

In case You ever wanted to use this library, use the following
instructions.
```sh
# in the following directories artifacts are stored
export $LOCAL_LIBRARY_LIB_PATH=/your/custom/path
export $LOCAL_LIBRARY_INCLUDE_PATH=/your/custom/path
chmod +x ./buildlib.sh
./buildlib.sh

# Compiling your program
gcc -L$LOCAL_LIBRARY_LIB_PATH -I$LOCAL_LIBRARY_INCLUDE_PATH -lstrings -o example example.c
./example
```
