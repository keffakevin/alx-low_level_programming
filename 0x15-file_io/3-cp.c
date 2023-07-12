#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
	char *fileFrom;
	char *fileTo;
	int fdFrom;
	int fdTo;
	char buffer[1024];
	ssize_t bytesRead;
	ssize_t bytesWritten;

	if (argc != 3)
	{
	fprintf(stderr, "Usage: cp file_from file_to\n");
	exit(1);
	}

	fileFrom = argv[1];
	fileTo = argv[2];

	fdFrom = open(fileFrom, O_RDONLY);
	if (fdFrom == -1)
	{
	fprintf(stderr, "Error: Can't read from file %s\n", fileFrom);
	exit(1);
	}

	fdTo = open(fileTo, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
	if (fdTo == -1)
	{
	fprintf(stderr, "Error: Can't write to %s\n", fileTo);
	exit(1);
	}

	while ((bytesRead = read(fdFrom, buffer, sizeof(buffer))) > 0)
	{
	bytesWritten = write(fdTo, buffer, bytesRead);
	if (bytesWritten != bytesRead)
	{
		fprintf(stderr, "Error: Can't write to %s\n", fileTo);
		exit(1);
	}
	}
	if (bytesRead == -1)
	{
	fprintf(stderr, "Error: Can't read from file %s\n", fileFrom);
	exit(1);
	}

	if (close(fdFrom) == -1)
	{
	fprintf(stderr, "Error: Can't close fd %d\n", fdFrom);
	exit(1);
	}
	if (close(fdTo) == -1)
	{
	fprintf(stderr, "Error: Can't close fd %d\n", fdTo);
	exit(1);
	}

	return(0);
}

