#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
/**
 * read_textfile - Reads a text file and prints it to the POSIX standard output
 * @filename: Name of the text file to read
 * @letters: Number of letters to read and print
 *
 * Return: Actual number of letters read and printed on success, 0 on failure
 */

ssize_t read_textfile(const char *filename, size_t letters)
{
	int fd;
	ssize_t rd, wr;
	char *buf;

	if (filename == NULL)
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	buf = malloc(sizeof(char) * letters);
	if (buf == NULL)
		return (0);
	rd = read(fd, buf, letters);
	if (rd == -1)
		return (0);
	wr = write(STDOUT_FILENO, buf, rd);
	if (wr == -1 || wr != rd)
		return (0);
	close(fd);
	free(buf);
	return (wr);
}
