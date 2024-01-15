#!bin/bash

# Compile each .c file into an object file
gcc -c -Wall -Werror -fPIC *.c

# Create the dynamic library
gcc -shared -o liball.so *.o

# Delete all the object files
rm *.o
