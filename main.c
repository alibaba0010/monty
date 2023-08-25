#define  _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
* main - interprets Monty code
* @argc: number of arguments
* @argv: location of Monty file
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
    char *file_content;
    FILE *monty_file;
    size_t content_size = 0;
    ssize_t line_read = 1;
    stack_t *stack = NULL;
    unsigned int line_number = 0;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    monty_file = fopen(argv[1], "r");
    bus.file = monty_file;

    if (!monty_file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (line_read > 0)
    {
        file_content = NULL;
        line_read = getline(&file_content, &content_size, monty_file);
        bus.content = file_content;
        line_number++;

        if (line_read > 0)
        {
            execute(file_content, &stack, line_number, monty_file);
        }

        free(file_content);
    }

    free_stack(stack);
    fclose(monty_file);
    return (0);
}

