#include "monty.h"
/**
 * print_char_at_top - prints the character at the top of the stack,
 * followed by a new line
 * @stack_top: pointer to the top of the stack
 * @line_number: line number in the file
 * Return: no return
 */
void f_pchar(stack_t **stack_top, unsigned int line_number)
{
    stack_t *current_node;

    current_node = *stack_top;
    if (!current_node)
    {
        fprintf(stderr, "L%d: can't print, stack empty\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_top);
        exit(EXIT_FAILURE);
    }
    if (current_node->n > 127 || current_node->n < 0)
    {
        fprintf(stderr, "L%d: can't print, value out of range\n", line_number);
        fclose(bus.file);
        free(bus.content);
        free_stack(*stack_top);
        exit(EXIT_FAILURE);
    }
    printf("%c\n", current_node->n);
}

