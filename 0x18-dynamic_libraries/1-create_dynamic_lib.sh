#bin/bash

# Compile each .c file into an object file
for file in *.c; do
	gcc -c -fPIC "$file" -o "${file%.*}.o"
done

# Create the dynamic library
gcc -shared -o liball.so *.o

# Delete all the object files
rm *.o
