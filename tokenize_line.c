#include "monty.h"

/**
 * tokenize_line - function to tokenize line from files
 *
 * Return: nothing
 */

void tokenize_line(void)
{
	int i = 0;
	char *dels = " \n", *token = NULL, *linecpy = NULL;

	linecpy = malloc(sizeof(char) * (strlen(global_fd->line) + 1));
	strcpy(linecpy, global_fd->line);
	global_fd->num_tokens = 0;
	token = strtok(linecpy, dels);
	while (token)
	{
		global_fd->num_tokens += 1;
		token = strtok(NULL, dels);
	}

	global_fd->tokens = malloc(sizeof(char *) * (global_fd->num_tokens + 1));
	strcpy(linecpy, global_fd->line);
	token = strtok(linecpy, dels);
	while (token)
	{
		global_fd->tokens = malloc(sizeof(char *) *
				(strlen(token) + 1));
		if (global_fd->tokens[i] == NULL)
		{
			malloc_failed();
		}
		strcpy(global_fd->tokens[i], token);
		token = strtok(NULL, dels);
		i++;
	}
	global_fd->tokens[i] = NULL;
	free(linecpy);
}

