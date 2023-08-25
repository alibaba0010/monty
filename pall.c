#include "monty.h"
/**
 * print_stack - prints the stack
 * @stack: stack head
 * @line_number: no used
 * Return: no return
*/
void f_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;

	current = *stack;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

