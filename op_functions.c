#include "monty.h"

/**
 * push - add data to stack
 * @stack: address of pointer to first node of stack(last added)
 * @line_number: line number where the instruction was provided
 *
 * Return: void
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new = NULL;
	(void)line_number;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		print_error("malloc");

	new->n = data;
	new->prev = NULL;
	new->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * pall - prints all nodes in stack
 * @stack: address of pointer to first node stack(last item added)
 * @line_number: line number of instruction
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
