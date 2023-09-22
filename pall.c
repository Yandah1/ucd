#include "monty.h"

/**
 * pall - Prints all elements in the stack.
 * @stack: pointer
 * @lineNum: line number where the function is called
 *
 */
void pall(stack_t **stack, unsigned int lineNum)
{
	stack_t *temp;

	if (global_fd->head == NULL)
		return;

	(void) lineNum;
	(void) stack;

	temp = global_fd->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
