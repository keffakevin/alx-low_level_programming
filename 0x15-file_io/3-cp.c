#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

/**
 * copy_file - copies the contents of one file to another file
 *
 * @src: file to copy from
 * @dest: file to copy to
 * Return: 0 on success, -1 on failure
 */
int copy_file(const char *src, const char *dest)
{
    int fd_src, fd_dest, n;
    char buffer[BUFFER_SIZE];

    /* Open source file for reading */
    fd_src = open(src, O_RDONLY);
    if (fd_src == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
        return (98);
    }

    /* Open destination file for writing */
    fd_dest = open(dest, O_WRONLY | O_CREAT | O_TRUNC, 0664);
    if (fd_dest == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
        return (99);
    }

    /* Copy contents from source file to destination file */
    while ((n = read(fd_src, buffer, BUFFER_SIZE)) > 0)
    {
        if (write(fd_dest, buffer, n) != n)
        {
            dprintf(STDERR_FILENO, "Error: Can't write to %s\n", dest);
            return (99);
        }
    }

    /* Check for read error */
    if (n == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", src);
        return (98);
    }

    /* Close file descriptors */
    if (close(fd_src) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_src);
        return (100);
    }

    if (close(fd_dest) == -1)
    {
        dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", fd_dest);
        return (100);
    }

    return (0);
}

/**
 * main - entry point
 *
 * @argc: argument count
 * @argv: argument vector
 * Return: 0 on success, 97 on invalid number of arguments,
 * 98 if can't read from file, 99 if can't write to file, 100 if can't close file
 */
int main(int argc, char **argv)
{
    if (argc != 3)
    {
        dprintf(STDERR_FILENO, "Usage: %s file_from file_to\n", argv[0]);
        return (97);
    }

    return (copy_file(argv[1], argv[2]));
}
