#include "monty.h"

/**
 * f_add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void f_add(stack_t **head, unsigned int counter)
{
    stack_t *h = *head;

    if (stack_length(h) < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        clean_exit(head);
    }

    int sum = h->n + h->next->n;
    h->next->n = sum;
    *head = h->next;
    free_and_pop(h);
}

/**
 * stack_length - returns the number of elements in the stack
 * @head: stack head
 * Return: number of elements
 */
int stack_length(stack_t *head)
{
    int len = 0;
    while (head)
    {
        head = head->next;
        len++;
    }
    return len;
}

/**
 * clean_exit - performs cleanup and exits with failure
 * @head: stack head
 * Return: doesn't return
 */
void clean_exit(stack_t **head)
{
    fclose(bus.file);
    free(bus.content);
    free_stack(*head);
    exit(EXIT_FAILURE);
}

/**
 * free_and_pop - frees the top element of the stack
 * @node: node to be freed
 */
void free_and_pop(stack_t *node)
{
    if (node)
    {
        stack_t *next = node->next;
        free(node);
        if (next)
            next->prev = NULL;
    }
}

