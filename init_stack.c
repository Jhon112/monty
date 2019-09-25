#include "monty.h"

/**
 * main - main function (entry point)
 * @argc: number of arguments (Must be two)
 * @argv: pointer to list of arguments
 *
 * Return: 0 always
 */
int main(int argc, char *argv[])
{
	/* variable to hold the fd of open sys call*/
	int fd = 0;
	stack_t *top = NULL;
	char *bytecode = NULL;
	ssize_t bytes_read;

	if (argc != 2)
		print_error("usage");

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		print_error("open", argv[1]);

	return (0);

}
