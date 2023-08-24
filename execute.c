#include "monty.h"
/**
 * execute_operation - performs the requested operation
 * @stack: pointer to the stack
 * @counter: line number
 * @file: pointer to the Monty file
 * @content: line content
 * Return: returns 0 on success, 1 otherwise
 */
int execute_operation(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opcodes[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };
    unsigned int i = 0;
    char *operation;

    operation = strtok(content, " \n\t");
    if (operation && operation[0] == '#')
        return 0;
    
    bus.arg = strtok(NULL, " \n\t");
    
    while (opcodes[i].opcode && operation)
    {
        if (strcmp(operation, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, counter);
            return 0;
        }
        i++;
    }

    if (operation && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }
    
    return 1;
}

