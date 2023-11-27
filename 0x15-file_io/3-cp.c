#include "main.h"

#define BUFFER_SIZE 1024

/**
 * print_error_and_exit - Entry point
 *
 *  * @code: the exit error code
 *  * @message:  the error message
 *  * @filename:  the filename
 *
 * Description: Function that print an error message to the standard
 * error stream and exit the program with a specified exit code.
 *
 * Return: void
 *
 */

void print_error_and_exit(int code, const char *message, const char *filename)
{
	dprintf(STDERR_FILENO, message, filename);
	exit(code);
}

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv:  arguments value
 *
 * Description: Function that copies the content of a file to another file
 *
 * Return: 0 in success
 *
 */

int main(int argc, char *argv[])
{
	const char *file_from, *file_to;
	int fd_from, fd_to;

	char buffer[BUFFER_SIZE];
	ssize_t bytes_read = BUFFER_SIZE, bytes_written;

	if (argc != 3)
		print_error_and_exit(97, "%s\n", "Usage: cp file_from file_to");

	file_from = argv[1], file_to = argv[2];
	fd_from = open(file_from, O_RDONLY);

	if (fd_from == -1)
		print_error_and_exit(98, "Error: Can't read from file %s\n", file_from);

	fd_to =
		open(file_to, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR |
			S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (fd_to == -1)
		print_error_and_exit(99, "Error: Can't write to file %s\n", file_to);

	while (bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd_from, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			print_error_and_exit(98, "Error: Can't read from file %s\n", file_from);

		bytes_written = write(fd_to, buffer, bytes_read);
		if (bytes_written == -1)
			print_error_and_exit(99, "Error: Can't write to file %s\n", file_to);
	}
	if (close(fd_from) == -1)
		print_error_and_exit(100, "Error: Can't close fd %d\n", file_from);

	if (close(fd_to) == -1)
		print_error_and_exit(100, "Error: Can't close fd %d\n", file_to);

	return (0);
}
