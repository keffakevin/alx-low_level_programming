#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * main - Entry point of the program
 * @argc: Number of command-line arguments
 * @argv: Array of command-line arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr elf_header;

	if (argc != 2)
	{
		write(2, "Usage: ", 7);
		write(2, argv[0], strlen(argv[0]));
		write(2, " elf_filename\n", 14);
		exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		write(2, "Error: Could not open file ", 27);
		write(2, argv[1], strlen(argv[1]));
		write(2, "\n", 1);
		exit(98);
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
		write(2, "Error: Could not read ELF header from file ", 43);
		write(2, argv[1], strlen(argv[1]));
		write(2, "\n", 1);
		exit(98);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
	    elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	    elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	    elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
		write(2, "Error: File ", 12);
		write(2, argv[1], strlen(argv[1]));
		write(2, " is not an ELF file\n", 20);
		exit(98);
	}

	write(1, "Magic: ", 7);
	putchar(elf_header.e_ident[EI_MAG0]);
	putchar(' ');
	putchar(elf_header.e_ident[EI_MAG1]);
	putchar(' ');
	putchar(elf_header.e_ident[EI_MAG2]);
	putchar(' ');
	putchar(elf_header.e_ident[EI_MAG3]);
	putchar('\n');

	printf("Class: %x\n", elf_header.e_ident[EI_CLASS]);
	printf("Data: %x\n", elf_header.e_ident[EI_DATA]);
	printf("Version: %x\n", elf_header.e_ident[EI_VERSION]);
	printf("OS/ABI: %x\n", elf_header.e_ident[EI_OSABI]);
	printf("ABI Version: %x\n", elf_header.e_ident[EI_ABIVERSION]);
	printf("Type: %x\n", elf_header.e_type);
	printf("Entry point address: %x\n", elf_header.e_entry);

	close(fd);
	return (0);
}

