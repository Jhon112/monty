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
	unsigned int line_number = 0;
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
						      line, fl, top);
			if (_strcmp(instruction.opcode, "push") == 0)
			{
				push_token = strtok(NULL, DELIM);
				if (!push_token || is_number(push_token) == -1)
					print_error_functions("integer",
							      line_number,
							      line, fl, top);
				data = atoi(push_token);
			}
			instruction.f(&top, line_number);
			break;
		}
	}
	free(line);
	fclose(fl);
	free_dlistint(top);
	return (0);
}

/**
 * free_dlistint - frees memory from a list
 * @head: pointer to the first node
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	stack_t *next, *current;

	current = head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
