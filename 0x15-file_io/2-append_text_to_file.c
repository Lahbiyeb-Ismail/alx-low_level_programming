#include "main.h"

/**
 * append_text_to_file - Entry point
 *
 *  * @filename: is the name of the file to create
 *  * @text_content:  is a NULL terminated string to write to the file
 *
 * Description: Function that creates a file.
 *
 * Prototype:
 * int create_file(const char *filename, char *text_content);
 *
 * Do not create the file if it does not exist
 *
 *
 * Return: 1 on success, -1 on failure
 * if filename is NULL return -1
 *
 * If text_content is NULL, do not add anything to the file.
 * Return 1 if the file exists and -1 if the file does not exist or if
 * you do not have the required permissions to write the file
 *
 */

int append_text_to_file(const char *filename, char *text_content)
{
	ssize_t write_count, file_handler;

	if (filename == NULL)
		return (-1);

	file_handler =
		open(filename, O_WRONLY | O_APPEND);

	if (file_handler == -1)
		return (-1);

	if (!text_content)
		if (file_handler)
			return (1);

	write_count = write(file_handler, text_content, strlen(text_content));

	if (write_count == -1)
	{
		close(file_handler);
		return (-1);
	}

	close(file_handler);

	return (1);
}
