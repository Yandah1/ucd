#include "monty.h"
/**
 * free_tokens - Frees token memory
 *
 */
void free_tokens(void)
{
	int i = 0;

	if (global_fd->tokens == NULL)
		return;

	while (global_fd-tokens[i])
	{
		free(global_fd-.tokens[i]);
		i++;
	}
	free(global_fd->tokens);
	global_fd->tokens = NULL;
}
