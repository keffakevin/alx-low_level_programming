#include <stdio.h>
#include "main.h"
#include <unistd.h>
#include <fcntl.h>

/**
 * read_textfile - reads a text file and prints it to the POSIX standard output
 * @filename: the name of the file to read
 * @letters: the maximum number of letters to read and print
 *
 * Return: the actual number of letters read and printed.
 */
ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t nread, nwritten = 0;
	char buffer[1024];

	if (filename == NULL)
	return (0);

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	return (0);

	while (letters > 0 && (nread = read(fd, buffer, sizeof(buffer))) > 0)
	{
	if (write(STDOUT_FILENO, buffer, nread) != nread)
	{
	close(fd);
	return (0);
	}
	nwritten += nread;
	letters -= nread;
	}

	close(fd);
	return (nwritten);
}
