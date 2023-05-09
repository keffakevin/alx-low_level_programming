#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

/**
 * append_text_to_file - appends text to the end of a file
 * @filename: the name of the file
 * @text_content: a NULL terminated string to add to the file
 *
 * Return: 1 on success, -1 on failure
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, ret, len = 0;

	if (!filename)
		return (-1);

	if (text_content)
	{
		while (text_content[len])
			len++;
	}

	fd = open(filename, O_WRONLY | O_APPEND);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		ret = write(fd, text_content, len);
		if (ret == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
