#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

/**
 * print_error - Prints the error message to stderr and exits with 98.
 * @error_msg: The error message to print.
 */
void print_error(char *error_msg)
{
	dprintf(STDERR_FILENO, "%s\n", error_msg);
	exit(98);
}

/**
 * print_magic - Prints the magic bytes of the ELF header.
 * @e_ident: The ELF header identifier bytes.
 */
void print_magic(unsigned char *e_ident)
{
	int i;

	printf(" Magic:  ");
	for (i = 0; i < EI_NIDENT; i++)
		printf("%02x ", e_ident[i]);
	printf("\n");
}

/**
 * print_class - Prints the ELF class (32-bit or 64-bit).
 * @e_ident: The ELF header identifier bytes.
 */
void print_class(unsigned char *e_ident)
{
	printf("  Class:              ");
	switch (e_ident[EI_CLASS])
	{
		case ELFCLASS32:
			printf("ELF32\n");
			break;
		case ELFCLASS64:
			printf("ELF64\n");
			break;
		default:
			print_error("Invalid ELF class");
			break;
	}
}

/**
 * print_data - Prints the ELF data encoding (little endian or big endian).
 * @e_ident: The ELF header identifier bytes.
 */
void print_data(unsigned char *e_ident)
{
	printf(" Data:                 ");
	switch (e_ident[EI_DATA])
	{
		case ELFDATA2LSB:
			printf("2's complement, little endian\n");
			break;
		case ELFDATA2MSB:
                        printf("2's complement, big endian\n");
			break;
		default:
			print_error("Invalid ELF data encoding");
			break;
	}
}

/**
 * print_version - Prints the ELF version.
 * @e_ident: The ELF header identifier bytes.
 */
void print_version(unsigned char *e_ident)
{
	printf(" Version:                  %d (current)\n", e_ident[EI_VERSION]);
}

/**
 * print_osabi - Prints the OS/ABI.
 * @e_ident: The ELF header identifier bytes.
 */
void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI:                ");
	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_SYSV:
			printf("UNIX - System V\n");
			break;
		 case ELFOSABI_NETBSD:
                        printf("UNIX - NetBSD\n");
                        break;
		 case ELFOSABI_LINUX:
                        printf("UNIX - Linux\n");
                        break;
		 case ELFOSABI_SOLARIS:
                        printf("UNIX - Solaris\n");
                        break;
		default:
			printf("<unknown: %d>\n", e_ident[EI_OSABI]);
			break;
	}
}

/**
 * print_abiversion - Prints the ABI version.
 * @e_ident: The ELF header identifier bytes.
 */
void print_abiversion(unsigned char *e_ident)
{
	printf(" ABI Version:                  %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the ELF file type.
 * @e_type: The ELF file type.
 */
void print_type(uint16_t e_type)
{
	printf(" Type:                    ");
	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (Unknown type)\n");
			break;
		case ET_REL:
			printf("REL (Relocatable file)\n");
			break;
		case ET_EXEC:
                        printf("EXEC (Executable file)\n");
                        break;
		case ET_DYN:
                        printf("DYN (Shared object file)\n");
                        break;
		case ET_CORE:
                        printf("Core (Core file)\n");
                        break;
		default:
			printf("<unknown: %d>\n", e_type);
			break;
	}
}

/**
 * read_elf_header - Reads and prints information from the ELF header.
 * @fd: The file descriptor of the ELF file.
 */
void read_elf_header(int fd)
{
	Elf32_Ehdr elf_header;

	if (read(fd, &elf_header, sizeof(elf_header)) != sizeof(elf_header))
		print_error("Error: Unable to read ELF header");
	
	printf("ELF Header:\n");
	print_magic(elf_header.e_ident);
	print_class(elf_header.e_ident);
	print_data(elf_header.e_ident);
	print_version(elf_header.e_ident);
	print_osabi(elf_header.e_ident);
	print_abiversion(elf_header.e_ident);
	print_type(elf_header.e_type);
}
/**
 * main - Entry point.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
	int fd;

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s <ELF file>\n", argv[0]);
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("Error: Unable to open ELF file");

	read_elf_header(fd);
	close(fd);

	return (0);
}
