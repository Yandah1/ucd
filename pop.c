#include "monty.h"

/**
 * pop - remove top element from stack
 * @stack: pointer
 * @lineNum: line number where the function is called
 *
 */
void pop(stack_t **stack, unsigned int lineNum)
{
	(void) stack;

	if (global_fd->head == NULL)
	{
		dprintf(2, "L%d: can't pop am empty stack\n", lineNum);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	delete_stack_node();
	global_fd->stack_length -= 1;
}

/**
 * delete_stack_node -  delete node on the top
 *
 * Return: void
 */

void delete_stack_node(void)
{
	stack_t *temp;

	temp = global_fd->head;
	global_fd->head = temp->next;
	free(temp);
}
