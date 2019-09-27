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

/**
 * pint - prints the top
 * @stack: pointer to the top of the stack
 * @line_number: line of instruction
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * swap - swaps the first two elements of the stack
 * @stack: pointer to the top of stack
 * @line_number: line instruction
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int top, previous;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = current->n;
	previous = current->next->n;
	current->next->n = top;
	current->n = previous;
}

/**
 * nop - Does nothing
 * @stack: pointer to the top of stack
 * @line_number: line of instruction
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
