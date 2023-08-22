#include "monty.h"

/**
 * mod_operation - computes the rest of the division of the second
 * top element of the stack by the top element of the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
 */
void mod_operation(stack_t **stack, unsigned int line_number)
{
    stack_t *current;
    int stack_length = 0, result;

    current = *stack;
    while (current)
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    current = *stack;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    result = current->next->n % current->n;
    current->next->n = result;
    *stack = current->next;
    free(current);
}

