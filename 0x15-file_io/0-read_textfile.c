#include "main.h"

/**
 * read_textfile - Entry point
 *
 *  * @filename: A pointer to a text filename
 *  * @letters: is the number of letters it should read and print
 *
 * Description: Function that reads a text file and prints it to the
 * POSIX standard output.
 *
 * Prototype: size_t read_textfile(const char *filename, size_t letters);
 *
 * Return: the actual number of letters it could read and print
 * if the file can not be opened or read, return 0
 * if filename is NULL return 0
 * if write fails or does not write the expected amount of bytes, return 0
 *
 */

size_t read_textfile(const char *filename, size_t letters)
{
	FILE *file_handler;
	char c;
	size_t char_count = 0;

	if (!filename)
		return (0);

	file_handler = fopen(filename, "r");

	if (!file_handler)
		return (0);

	while ((c = fgetc(file_handler)) != EOF)
	{
		if (char_count >= letters)
			break;

		putchar(c);
		char_count++;
	}

	return (char_count);
}
