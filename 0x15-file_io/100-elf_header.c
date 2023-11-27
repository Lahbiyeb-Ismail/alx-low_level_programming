#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void check_elf(unsigned char *e_ident);
void print_magic(unsigned char *e_ident);
void print_class(unsigned char *e_ident);
void print_data(unsigned char *e_ident);
void print_version(unsigned char *e_ident);
void print_abi(unsigned char *e_ident);
void print_osabi(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf_fd);

/**
 * check_elf - Checks if a file is an ELF file.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: If the file is not an ELF file - exit code 98.
 */
void check_elf(unsigned char *e_ident)
{
	for (int index = 0; index < 4; index++)
	{
		if (e_ident[index] != 127 &&
			e_ident[index] != 'E' &&
			e_ident[index] != 'L' &&
			e_ident[index] != 'F')
		{
			fprintf(stderr, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * print_magic - Prints the magic numbers of an ELF header.
 * @e_ident: A pointer to an array containing the ELF magic numbers.
 *
 * Description: Magic numbers are separated by spaces.
 */
void print_magic(unsigned char *e_ident)
{
	printf("Magic:   ");
	for (int index = 0; index < EI_NIDENT; index++)
	{
		printf("%02x%s", e_ident[index], index == EI_NIDENT - 1 ? "\n" : " ");
	}
}

/**
 * print_class - Prints the class of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_class(unsigned char *e_ident)
{
	static const char *class_types[] = {
			"none", "ELF32", "ELF64" };

	printf("Class:                             %s\n", class_types[e_ident[EI_CLASS]]);
}

/**
 * print_data - Prints the data of an ELF header.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_data(unsigned char *e_ident)
{
	static const char *data_types[] = {
			"none", "2's complement, little endian", "2's complement, big endian" };

	printf("Data:                              %s\n", data_types[e_ident[EI_DATA]]);
}

/**
 * print_version - Prints the version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_version(unsigned char *e_ident)
{
	printf("Version:                           %d%s\n",
		e_ident[EI_VERSION], e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
}

/**
 * print_osabi - Prints the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array containing the ELF version.
 */
void print_osabi(unsigned char *e_ident)
{
	static const char *osabi_names[] = {
			"UNIX - System V", "UNIX - HP-UX", "UNIX - NetBSD", "UNIX - Linux",
			"UNIX - Solaris", "UNIX - IRIX", "UNIX - FreeBSD", "UNIX - TRU64",
			"ARM", "Standalone App" };

	unsigned char osabi = e_ident[EI_OSABI];
	if (osabi >= sizeof(osabi_names) / sizeof(osabi_names[0]))
	{
		printf("OS/ABI:                            <unknown: %x>\n", osabi);
	}
	else
	{
		printf("OS/ABI:                            %s\n", osabi_names[osabi]);
	}
}

/**
 * print_abi - Prints the ABI version of an ELF header.
 * @e_ident: A pointer to an array containing the ELF ABI version.
 */
void print_abi(unsigned char *e_ident)
{
	printf("ABI Version:                       %d\n", e_ident[EI_ABIVERSION]);
}

/**
 * print_type - Prints the type of an ELF header.
 * @e_type: The ELF type.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_type >>= 8;
	}

	static const char *type_names[] = {
			"NONE (None)", "REL (Relocatable file)", "EXEC (Executable file)",
			"DYN (Shared object file)", "CORE (Core file)" };

	if (e_type >= sizeof(type_names) / sizeof(type_names[0]))
	{
		printf("Type:                              <unknown: %x>\n", e_type);
	}
	else
	{
		printf("Type:                              %s\n", type_names[e_type]);
	}
}

/**
 * print_entry - Prints the entry point of an ELF header.
 * @e_entry: The address of the ELF entry point.
 * @e_ident: A pointer to an array containing the ELF class.
 */
void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	printf("Entry point address:               %s0x%lx\n",
		(e_ident[EI_CLASS] == ELFCLASS32) ? "0x" : "", e_entry);
}

/**
 * close_elf - Closes an ELF file.
 * @elf: The file descriptor of the ELF file.
 *
 * Description: If the file cannot be closed - exit code 98.
 */
void close_elf(int elf_fd)
{
	if (close(elf_fd) == -1)
	{
		fprintf(stderr, "Error: Can't close fd %d\n", elf_fd);
		exit(98);
	}
}

/**
 * main - Displays the information contained in the
 *        ELF header at the start of an ELF file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the file is not an ELF File or
 *              the function fails - exit code 98.
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "Error: Usage: %s <elf-file>\n", argv[0]);
		exit(98);
	}

	int elf_fd = open(argv[1], O_RDONLY);

	if (elf_fd == -1)
	{
		fprintf(stderr, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}

	Elf64_Ehdr header;
	ssize_t read_bytes = read(elf_fd, &header, sizeof(header));

	if (read_bytes == -1)
	{
		fprintf(stderr, "Error: %s\n", strerror(errno));
		close_elf(elf_fd);
		exit(98);
	}
	else if (read_bytes != sizeof(header))
	{
		fprintf(stderr, "Error: Incomplete header read\n");
		close_elf(elf_fd);
		exit(98);
	}

	check_elf(header.e_ident);
	printf("ELF Header:\n");
	print_magic(header.e_ident);
	print_class(header.e_ident);
	print_data(header.e_ident);
	print_version(header.e_ident);
	print_osabi(header.e_ident);
	print_abi(header.e_ident);
	print_type(header.e_type, header.e_ident);
	print_entry(header.e_entry, header.e_ident);

	close_elf(elf_fd);
	return (0);
}
