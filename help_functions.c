#include "monty.h"

/**
 * print_error - prints all the different errors according to its type
 * @error_type: pointer to string indicating type
 *
 * Return:  void - exit with EXIT_FAILURE
 */
void print_error(char  *error_type, ...)
{
	va_list replacers;

	va_start(replacers, error_type);
	if (_strcmp(error_type, "usage") == 0)
	{
		fprintf(stderr, "USAGE: monty file\n");
	}
	if (_strcmp(error_type, "open") == 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", va_arg(replacers,
								      char *));
	}
	if (_strcmp(error_type, "malloc") == 0)
	{
		fprintf(stderr, "Error: malloc failed\n");
	}
	exit(EXIT_FAILURE);
}

/**
 * print_error_functions - prints all the different errors according to type
 * @error_type: pointer to string indicating type
 *
 * Return:  void - exit with EXIT_FAILURE
 */
void print_error_functions(char  *error_type, ...)
{
	va_list replacers;

	va_start(replacers, error_type);
	if (_strcmp(error_type, "integer") == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n",
			va_arg(replacers, int));
	}

	free(va_arg(replacers, char *));
	fclose(va_arg(replacers, FILE *));
	exit(EXIT_FAILURE);
}

/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: negative numb if s1 major than s2
 * positive numb if s1 major s2
 * 0 if same
 */
int _strcmp(char *s1, char *s2)
{
	int i, a;

	for (i = 0; *(s1 + i) != '\0'; i++)
	{
	}

	for (a = 0; a < i; a++)
	{
		if (s1[a] != s2[a])
			return (s1[a] - s2[a]);
	}
	return (0);
}

/**
 * is_number - checks if the string is a number
 * @str: str to be compared
 *
 * Return: o if true, 1 otherwise
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if ((str[i] >= 48 && str[i] <= 57) || str[i] == 45)
			i++;
		else
			return (-1);
	}
	return (0);
}
