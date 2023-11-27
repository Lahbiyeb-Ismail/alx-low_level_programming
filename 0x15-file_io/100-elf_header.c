#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <elf.h>

/**
 * main - Entry point
 *
 *  * @argc: arguments count
 *  * @argv:  arguments value
 *
 * Description: Function that copies the content of a file to another file
 *
 * Return: 0 in success
 *
 */

int main(int argc, char **argv)
{
	int fd;
	Elf64_Ehdr *ehdr;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: %s elf_filename\n", argv[0]);
		exit(98);
	} fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		exit(98);
	}
	ehdr = mmap(NULL, sizeof(Elf64_Ehdr), PROT_READ, MAP_PRIVATE, fd, 0);
	if (ehdr == MAP_FAILED)
	{
		perror("mmap");
		exit(98);
	}
	if (ehdr->e_ident[EI_MAG0] != ELFMAG0 ||
		ehdr->e_ident[EI_MAG1] != ELFMAG1 ||
		ehdr->e_ident[EI_MAG2] != ELFMAG2 ||
		ehdr->e_ident[EI_MAG3] != ELFMAG3) {
		fprintf(stderr, "%s is not an ELF file\n", argv[1]);
		exit(98);
	}
	printf("Magic: %s\n", ehdr->e_ident);
	printf("Class: %s\n", ehdr->e_ident[EI_CLASS] == ELFCLASS64
		? "64-bit" : "32-bit");
	printf("Data: %s\n", ehdr->e_ident[EI_DATA] == ELFDATA2LSB
		? "little-endian" : "big-endian");
	printf("Version: %d\n", ehdr->e_ident[EI_VERSION]);
	printf("OS/ABI: %d\n", ehdr->e_ident[EI_OSABI]);
	printf("ABI Version: %d\n", ehdr->e_ident[EI_ABIVERSION]);
	printf("Type: %s\n", ehdr->e_type == ET_EXEC
		? "executable" : "shared object");
	printf("Entry point address: 0x%lx\n", ehdr->e_entry);
	munmap(ehdr, sizeof(Elf64_Ehdr));
	close(fd);
	return (0);
}
