#include "main.h"

/**
 * create_file - Entry point
 *
 *  * @filename: is the name of the file to create
 *  * @text_content:  is a NULL terminated string to write to the file
 *
 * Description: Function that creates a file.
 *
 * Prototype:
 * int create_file(const char *filename, char *text_content);
 *
 * if text_content is NULL create an empty file
 *
 * Return: 1 on success, -1 on failure
 * if filename is NULL return -1
 *
 */

int create_file(const char *filename, char *text_content)
{
	int file_handler;
	size_t write_count;

	if (filename == NULL)
		return (-1);

	file_handler =
		open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);

	if (file_handler == -1)
		return (-1);

	if (text_content != NULL)
	{
		size_t content_length = strlen(text_content);

		write_count = write(file_handler, text_content, content_length);

		if (write_count < content_length)
		{
			close(file_handler);
			return (-1);
		}
	}

	close(file_handler);

	return (1);
}
