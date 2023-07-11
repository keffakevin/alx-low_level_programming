#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

int main(int argc, char *argv[])
{
	int fd;
	Elf32_Ehdr elf_header;

	if (argc != 2)
	{
	fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
	exit(98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
	fprintf(stderr, "Error: Could not open file %s\n", argv[1]);
	exit(98);
	}

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
	{
	fprintf(stderr, "Error: Could not read ELF header from file %s\n", argv[1]);
	exit(98);
	}

	if (elf_header.e_ident[EI_MAG0] != ELFMAG0 ||
	elf_header.e_ident[EI_MAG1] != ELFMAG1 ||
	elf_header.e_ident[EI_MAG2] != ELFMAG2 ||
	elf_header.e_ident[EI_MAG3] != ELFMAG3)
	{
	fprintf(stderr, "Error: File %s is not an ELF file\n", argv[1]);
	exit(98);
	}

	printf("Magic: %x %x %x %x\n",
	elf_header.e_ident[EI_MAG0],
	elf_header.e_ident[EI_MAG1],
	elf_header.e_ident[EI_MAG2],
	elf_header.e_ident[EI_MAG3]);
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
