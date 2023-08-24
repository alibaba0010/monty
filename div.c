#include "monty.h"
/**
 * f_div - Divides the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int length = 0, quotient;

    current = *head;
    while (current)
    {
        current = current->next;
        length++;
    }
    if (length < 2)
    {
        fprintf(stderr, "L%d: Unable to perform division, insufficient stack elements\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    current = *head;
    if (current->n == 0)
    {
        fprintf(stderr, "L%d: Division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }
    quotient = current->next->n / current->n;
    current->next->n = quotient;
    *head = current->next;
    free(current);
}

