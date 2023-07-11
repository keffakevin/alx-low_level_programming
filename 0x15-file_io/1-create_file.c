#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

/**
* create_file - Creates a new file with text content to it.
* @filename: The name of the file to be created.
* @text_content: The text content to be written to the file.
*
* Return: Upon success, returns 1. Otherwise, returns -1.
*/

int create_file(const char *filename, char *text_content)
{
	int fd;
	int write_status;
	int close_status;

	if (filename == NULL)
	return (-1);

	fd = open(filename, O_CREAT | O_WRONLY | O_TRUNC, S_IRUSR | S_IWUSR);
	if (fd == -1)
	return (-1);

	if (text_content != NULL)
	{
	write_status = write(fd, text_content, strlen(text_content));
	if (write_status == -1)
		return (-1);
	}

	close_status = close(fd);
	if (close_status == -1)
	return (-1);
	return (1);
}
