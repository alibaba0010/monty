#include "monty.h"

/**
 * f_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_pchar(stack_t **head, unsigned int counter)
{
    stack_t *h = *head;

    if (!h)
    {
        print_error_and_exit(counter, "can't pchar, stack empty");
    }

    if (h->n > 127 || h->n < 0)
    {
        print_error_and_exit(counter, "can't pchar, value out of range");
    }

    printf("%c\n", h->n);
}

/**
 * print_error_and_exit - prints error message, frees memory, and exits
 * @counter: line_number
 * @msg: error message
 * Return: no return
 */
void print_error_and_exit(unsigned int counter, const char *msg)
{
    fprintf(stderr, "L%d: %s\n", counter, msg);
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

