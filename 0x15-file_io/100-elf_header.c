#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <elf.h>

/**
 * main - entry point
 * @argc: number of arguments
 * @argv: array of arguments
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	int fd;
	Elf64_Ehdr header;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: elf_header elf_filename\n");
		exit(98);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (read(fd, &header, sizeof(header)) != sizeof(header))
	{
		dprintf(STDERR_FILENO, "Error: Can't read from file %s\n", argv[1]);
		exit(98);
	}
	if (header.e_ident[EI_MAG0] != ELFMAG0 ||
		header.e_ident[EI_MAG1] != ELFMAG1 ||
		header.e_ident[EI_MAG2] != ELFMAG2 ||
		header.e_ident[EI_MAG3] != ELFMAG3)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file - %s\n", argv[1]);
		exit(98);
	}
	printf("ELF Header:\n");
	printf("  Magic:   ");
	printf("%02x %02x %02x %02x\n",
		header.e_ident[EI_MAG0], header.e_ident[EI_MAG1],
		header.e_ident[EI_MAG2], header.e_ident[EI_MAG3]);
	printf("  Class:                             ");
	if (header.e_ident[EI_CLASS] == ELFCLASS32)
		printf("ELF32\n");
	else if (header.e_ident[EI_CLASS] == ELFCLASS64)
		printf("ELF64\n");
	else
		printf("<unknown: %x>\n", header.e_ident[EI_CLASS]);
	printf("  Data:                              ");
	if (header.e_ident[EI_DATA] == ELFDATA2LSB)
		printf("2's complement, little endian\n");
	else if (header.e_ident[EI_DATA] == ELFDATA2MSB)
		printf("2's complement, big endian\n");
	else
		printf("<unknown: %x>\n", header.e_ident[EI_DATA]);
	printf("  Version:                           ");
	if (header.e_ident[EI_VERSION] == EV_CURRENT)
		printf("%d (current)\n", header.e_ident[EI_VERSION]);
	else
		printf("%d\n", header.e_ident[EI_VERSION]);
	printf("  OS/ABI:                            ");
	if (header.e_ident[EI_OSABI] == ELFOSABI_SYSV)
		printf("UNIX - System V\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_HPUX)
		printf("UNIX - HP-UX\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_NETBSD)
		printf("UNIX - NetBSD\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_LINUX)
		printf("UNIX - Linux\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_SOLARIS)
		printf("UNIX - Solaris\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_AIX)
		printf("UNIX - AIX\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_IRIX)
		printf("UNIX - IRIX\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_FREEBSD)
		printf("UNIX - FreeBSD\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_TRU64)
		printf("UNIX - TRU64\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_MODESTO)
		printf("Novell - Modesto\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_OPENBSD)
		printf("UNIX - OpenBSD\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_ARM_AEABI)
		printf("ARM EABI\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_ARM)
		printf("ARM\n");
	else if (header.e_ident[EI_OSABI] == ELFOSABI_STANDALONE)
		printf("Standalone App\n");
	else
		printf("<unknown: %x>\n", header.e_ident[EI_OSABI]);
	printf("  ABI Version:                       %d\n",
		header.e_ident[EI_ABIVERSION]);
	printf("  Type:                              ");
	if (header.e_type == ET_NONE)
		printf("NONE (None)\n");
	else if (header.e_type == ET_REL)
		printf("REL (Relocatable file)\n");
	else if (header.e_type == ET_EXEC)
		printf("EXEC (Executable file)\n");
	else if (header.e_type == ET_DYN)
		printf("DYN (Shared object file)\n");
	else if (header.e_type == ET_CORE)
		printf("CORE (Core file)\n");
	else
		printf("<unknown: %x>\n", header.e_type);
	printf("  Entry point address:               0x%x\n",
		(unsigned int)header.e_entry);
	close(fd);
	return (0);
}
