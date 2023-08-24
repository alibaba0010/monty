#include "monty.h"
/**
 * f_add - Adds the top two elements of the stack.
 * @head: Pointer to the stack's head.
 * @counter: Line number.
 * Return: No return value.
 */
void f_add(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int stack_length = 0, sum;

    current = *head;

    while (current)
    {
        current = current->next;
        stack_length++;
    }

    if (stack_length < 2)
    {
        fprintf(stderr, "L%d: Unable to add, insufficient elements in stack\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    sum = current->n + current->next->n;
    current->next->n = sum;
    *head = current->next;
    free(current);
}

