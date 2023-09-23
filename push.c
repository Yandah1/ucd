#include "monty.h"
#include <stdio.h>
/**
 * push - push interger on the stack
 * @stack: pointer
 * @lineNum: line num where push is called
 *
 */
void push(stack_t **stack, unsigned int lineNum)
{
	if (global_fd->num_tokens <= 1 || !(is_number(global_fd->tokens[1])))
	{
		free_global_fd();
		dprintf(2, "L%d: usage: push integer\n", lineNum);
		exit(EXIT_FAILURE);
	}

	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
		malloc_failed();
	(*stack)->next = (*stack)->prev = NULL;

	(*stack)->n = (int) atoi(global_fd->tokens[1]);

	if (global_fd->head != NULL)
	{
		(*stack)->next = global_fd->head;
		global_fd->head->prev = *stack;
	}
	global_fd->head = *stack;
	global_fd->stack_length += 1;
}
