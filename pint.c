#include "monty.h"
#include <stdio.h>

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer
 * @lineNum: line number whare pint is called
 */
void pint(stack_t **stack, unsigned int lineNum)
{
	(void) stack;

	if (global_fd->head == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack is empty\n", lineNum);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", global_fd->head->n);
}
