#include "monty.h"
bus_t final_bus = {NULL, NULL, NULL, 0};
/**
 * main - Monty code interpreter
 * @argc: count of arguments
 * @argv: Monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *file_content;
	FILE *file_ptr;
	size_t content_size = 0;
	ssize_t read_result = 1;
	stack_t *final_stack = NULL;
	unsigned int line_counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_ptr = fopen(argv[1], "r");
	final_bus.file = file_ptr;
	if (!file_ptr)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_result > 0)
	{
		file_content = NULL;
		read_result = getline(&file_content, &content_size, file_ptr);
		final_bus.content = file_content;
		line_counter++;
		if (read_result > 0)
		{
			execute(file_content, &final_stack, line_counter, file_ptr);
		}
		free(file_content);
	}
	free_stack(final_stack);
	fclose(file_ptr);
	return (0);
}

