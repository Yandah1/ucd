#include <stdio.h>
#include <stdlib.h>
#include "monty.h"

Global_d *global_fd = NULL;

/**
 * main - entry point
 * @argc: the number of command line
 * @argv: the pointer to an array of string
 * Description: prints alphabets in lowercases
 *
 * Return: 0
 */
int main(int argc, char **argv)
{
	size_t n = 0;

	validate_arguments(argc);
	initialize_global_fd();
	get_stream(argv[1]);

	while (getline(&global_fd->line, &n, global_fd->stream) != -1)
	{
		printf("%s", global_fd->line);
	}

	return (0);
}