#include "monty.h"

/**
 * free_global_fd - free memory
 *
 */
void free_global_fd(void)
{
	if (global_fd == NULL)
		return;

	if (global_fd->instruction)
	{
		free(global_fd->instruction);
		global_fd->instruction = NULL;
	}

	free_head();

	if (global_fd->line)
	{
		free(global_fd->line);
		global_fd->line = NULL;
	}

	free(global_fd);
}

/**
 * free_head - frees memory
 *
 */
void free_head(void)
{
	if (global_fd->head)
		free_stack(global_fd->head);

	global_fd->head = NULL;
}

/**
 * free_stack - frees nodes
 * @head: first node
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
	{
		free_stack(head->next);
	}

	free(head);
}

/**
 * free_all_args - frees all memory of args
 */
void free_all_args(void)
{
	close_stream();
	free_tokens();
	free_global_fd();
}
