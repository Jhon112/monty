#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * @head: pointer to top of stack
 * @line_number: line of instruction
 *
 * Return: void
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	current->next->n += current->n;
	*head = current->next;
	(*head)->prev = NULL;
	free(current);
}

/**
 * pop - removes the top element of the stack.
 * @head: pointer to top of stack
 * @line_number: line of instruction
 *
 * Return: void
 */
void pop(stack_t **head, unsigned int line_number)
{
	stack_t *current = *head;

	if (current == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (current->next == NULL)
	{
		free(current);
		*head = NULL;
	}
	else
	{
		*head = current->next;
		(*head)->prev = NULL;
		free(current);
	}

}
