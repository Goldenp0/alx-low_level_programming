#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void print_osabi(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * print_osabi - Prints OS/ABI of ELF header
 * @e_ident: pointer to array contains the ELF version
 */

void print_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
		case ELFOSABI_NONE:
			printf("UNIX - System V\n");
			break;
		case ELFOSABI_HPUX:
			printf("UNIX - HP-UX\n");
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
		case ELFOSABI_IRIX:
			printf("UNIX - IRIX\n");
			break;
		case ELFOSABI_FREEBSD:
			printf("UNIX - FreeBSD\n");
			break;
		case ELFOSABI_TRU64:
			printf("UNIX - TRU64\n");
			break;
		case ELFOSABI_ARM:
			printf("ARM\n");
			break;
		case ELFOSABI_STANDALONE:
			printf("standalone App\n");
			break;
		default:
			printf("unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * print_abi - prints ABI version of Elf header
 * @e_ident: pointer array contains ELF ABI version
 */

void print_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
			e_ident[EI_ABIVERSION]);
}

/**
 * print_type - prints type of ELF header
 * @e_type: ELF type.
 * @e_ident: pointer array contains ELF class
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;
	printf(" Type: ");

	switch (e_type)
	{
		case ET_NONE:
			printf("NONE (None)\n");
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
			printf("CORE (Core file)\n");
			break;
		default:
			printf("<unknown: %x>\n", e_type);
	}
}

/**
 * print_entry - print entrry point of ELF header
 * @e_entry: Address of ELF entry point
 * @e_ident: pointer array contains ELF class.
 */

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - Close ELF file.
 * @elf: file descriptor of ELF file
 *
 * Description: if file cannot close - exit code 98
 */

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
				"ERROR: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - Display contained information in the
 * ELF header at the start of ELF file
 * @argc: the digit of arguments supplied into the program
 * @argv: Array pointer to the arguments.
 *
 * Return: 0 success
 *
 * Description: if the file is not Elf file or
 * the func fails then exit code 98.
 */

int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int w, s;

	w = open(argv[1], O_RDONLY);
	if (w == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n",
				argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(w);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n",
				argv[1]);
		exit(98);
	}
	s = read(w, header, sizeof(Elf64_Ehdr));
	if (s == -1)
	{
		free(header);
		close_elf(w);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n",
				argv[1]);
		exit(98);
	}

	printf("ELF Header:\n");
	print_osabi(header->e_ident);
	print_abi(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(w);
	return (0);
}
