#include "monty.h"

/**
 * f_div - divides the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void f_div(stack_t **head, unsigned int counter)
{
    stack_t *h = *head;
    int len = 0, aux;

    // Calculate the length of the stack
    while (h)
    {
        h = h->next;
        len++;
    }

    // Check if there are enough elements for division
    if (len < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        handle_error_cleanup(head);
    }

    h = *head;
    // Check for division by zero
    if (h->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        handle_error_cleanup(head);
    }

    // Perform division
    aux = h->next->n / h->n;
    h->next->n = aux;
    *head = h->next;
    free(h);
}

/**
 * handle_error_cleanup - closes file, frees memory, and exits on error
 * @head: stack head
 * Return: no return
 */
void handle_error_cleanup(stack_t **head)
{
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

