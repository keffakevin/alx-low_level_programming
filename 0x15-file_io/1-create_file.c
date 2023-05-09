#include <unistd.h>
#include <fcntl.h>

/**
 * create_file - creates a file with the given name.
 * @filename: the name of the file to create.
 * @text_content: the text to write to the file.
 *
 * Return: 1 on success, -1 on failure
 */
int create_file(const char *filename, char *text_content)
{
	int fd, flags, mode = S_IRUSR | S_IWUSR;
	ssize_t nwritten = 0;

	if (filename == NULL)
		return (-1);

	if (text_content == NULL)
		text_content = "";

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	fd = open(filename, flags, mode);
	if (fd == -1)
		return (-1);


	while (*text_content != '\0')
	{
		nwritten = write(fd, text_content, 1);
		if (nwritten != 1)
		{
			close(fd);
			return (-1);
		}
		text_content++;
	}

	close(fd);
	return (1);
}
