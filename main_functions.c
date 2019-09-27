#include "monty.h"

/**
 * get_instruction - returns the instruction according to the opcode found
 * @opcode: token gotten from file
 * @line_number: number of line were instructions was provided
 * @line: line read from file. Use to free in error case
 * @fl: file opened. Use to fclose in error case
 *
 * Return: pointer to struct instruction requested
 */
instruction_t get_instruction(char *opcode, int line_number, char *line,
			      FILE *fl)
{
	instruction_t instructions[] = {{"push", push}, {"pall", pall}};
	int length = 0, i = 0;

	length = (sizeof(instructions) / sizeof(instruction_t));
	while (i < length)
	{
		if (_strcmp(instructions[i].opcode, opcode) == 0)
			return (instructions[i]);
		i++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
	free(line);
	fclose(fl);
	exit(EXIT_FAILURE);
}
