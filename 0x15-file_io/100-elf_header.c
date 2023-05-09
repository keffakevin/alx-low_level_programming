#include <elf.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
* print_error - prints error message to stderr
* @msg: the error message to print
*
* Return: void
*/
void print_error(char *msg)
{
fprintf(stderr, "Error: %s\n", msg);
exit(98);
}

/**
* main - displays the information contained in the ELF header
* @argc: the number of arguments passed to the program
* @argv: an array of pointers to the arguments
*
* Return: 0 on success, 98 on error
*/
int main(int argc, char **argv)
{
int fd;
Elf64_Ehdr ehdr;

/* check for correct number of arguments */
if (argc != 2)
print_error("Incorrect number of arguments");

/* open the file for reading */
fd = open(argv[1], O_RDONLY);
if (fd == -1)
print_error("Cannot open file");

/* read the ELF header */
if (read(fd, &ehdr, sizeof(ehdr)) != sizeof(ehdr))
print_error("Cannot read ELF header");

/* check if file is an ELF file */
if (ehdr.e_ident[EI_MAG0] != ELFMAG0 || ehdr.e_ident[EI_MAG1] != ELFMAG1 ||
ehdr.e_ident[EI_MAG2] != ELFMAG2 || ehdr.e_ident[EI_MAG3] != ELFMAG3)
print_error("Not an ELF file");

/* print the information contained in the ELF header */
printf("ELF Header:\n");
printf("  Magic:   ");
for (int i = 0; i < EI_NIDENT; i++)
printf("%02x ", ehdr.e_ident[i]);
printf("\n");

printf("  Class:                             %s\n",
ehdr.e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
ehdr.e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "Invalid class");

printf("  Data:                              %s\n",
ehdr.e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
ehdr.e_ident[EI_DATA] == ELFDATA2MSB ? "2's complement, big endian" :
"Invalid data encoding");

printf("  Version:                           %d %s\n",
ehdr.e_ident[EI_VERSION], ehdr.e_ident[EI_VERSION] == EV_CURRENT ? "(current)" : "");

printf("  OS/ABI:                            ");
switch (ehdr.e_ident[EI_OSABI])
	{
	case ELFOSABI_SYSV:     printf("UNIX - System V\n"); break;
	case ELFOSABI_HPUX:     printf("UNIX - HP-UX\n"); break;
	case ELFOSABI_NETBSD:   printf("UNIX - NetBSD\n"); break;
	case ELFOSABI_LINUX:    printf("UNIX - GNU/Linux\n"); break;
	case ELFOSABI_SOLARIS:  printf("UNIX - Solaris\n"); break;
	case ELFOSABI_IRIX:     printf("UNIX - IRIX\n"); break;
	case ELFOSABI_FREEBSD:  printf("UNIX - FreeBSD\n"); break;
	case ELFOSABI_TRU64:    printf("UNIX - TRU;
