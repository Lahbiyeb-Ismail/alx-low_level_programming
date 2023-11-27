#include "main.h"

/**
 * free_buffer - Entry point
 *
 *  * @buffer: A pointer to a char's array
 *  * @file_handler: is the number of letters it should read and print
 *
 * Description: Helper function that free the buffer memory and close
 * the file_handler
 *
 * Return: 0
 *
 */

int free_buffer(char *buffer, int file_handler)
{
	free(buffer);
	close(file_handler);
	return (0);
}

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

ssize_t read_textfile(const char *filename, size_t letters)
{
	int file_handler;
	ssize_t read_count, write_count;
	char *buffer;

	if (!filename)
		return (0);

	file_handler = open(filename, O_RDONLY);

	if (file_handler == -1)
		return (0);

	buffer = malloc(sizeof(char) * letters);

	if (!buffer)
		free_buffer(buffer, file_handler);

	read_count = read(file_handler, buffer, letters);
	if (read_count == -1)
		free_buffer(buffer, file_handler);

	write_count = write(STDOUT_FILENO, buffer, read_count);
	if (write_count == -1 || write_count != read_count)
		free_buffer(buffer, file_handler);

	free(buffer);
	close(file_handler);

	return (write_count);
}


