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
	FILE *fl = NULL;
	stack_t *top = NULL;
	char *line = NULL, *token = NULL, *push_token = NULL;
	int line_number = 0;
	instruction_t instruction;

	if (argc != 2)
		print_error("usage");

	fl = fopen(argv[1], "r");
	if (fl == NULL)
		print_error("open", argv[1]);

	line = malloc(sizeof(char) * 1024);
	if (line == NULL)
		print_error("malloc");

	while (1)
	{
		if (fgets(line, 1024, fl) == NULL)
			break;
		line_number++;
		token = strtok(line, DELIM);
		while (token != NULL)
		{
			instruction = get_instruction(token, line_number,
						      line, fl);
			if (_strcmp(instruction.opcode, "push") == 0)
				push_token = strtok(NULL, DELIM);
			if (!push_token || is_number(push_token) == -1)
				print_error_functions("integer", line_number,
						      line, fl);
			data = atoi(push_token);
			printf("%p\n DATA: %d\n", instruction.f, data);
			token = strtok(NULL, DELIM);
		}
	}
	free(line);
	fclose(fl);
	return (0);

}
