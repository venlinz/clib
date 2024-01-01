#!/bin/sh

set -xe

gcc-13  -pedantic -Wall -Wextra -c strings.c
ar rcs libstrings.a strings.o

mkdir -p $LOCAL_LIBRARY_LIB_PATH/lib
mkdir -p $LOCAL_LIBRARY_INCLUDE_PATH/include

cp libstrings.a $LOCAL_LIBRARY_LIB_PATH/lib/
cp ./strings.h $LOCAL_LIBRARY_INCLUDE_PATH/include/
