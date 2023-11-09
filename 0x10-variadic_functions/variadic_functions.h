#ifndef VARIADIC_FUNCTIONS
#define VARIADIC_FUNCTIONS

#include <stdarg.h>
#include <stdio.h>
#include <string.h>


int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char *const format, ...);

/**
 * struct op - Struct op
 *
 * @specifier: The specifier type
 * @f: The function associated
 */
typedef struct op
{
	char *specifier;
	void (*f)(va_list);
} op_t;

void print_char(va_list args);
void print_int(va_list args);
void print_float(va_list args);
void print_string(va_list args);

#endif
