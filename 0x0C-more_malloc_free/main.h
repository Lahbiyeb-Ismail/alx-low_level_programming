#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>

void *malloc_checked(unsigned int b);
char *string_nconcat(char *s1, char *s2, unsigned int n);
void *_calloc(unsigned int nmemb, unsigned int size);
int *array_range(int min, int max);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
int main(int argc, char *argv[]);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
int is_valid_number(char *s);
void initValue(char *str, int totalLen);


#endif /* MAIN_H */
