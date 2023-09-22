#include "monty.h"

/**
 * fetch_instruction - set instructions
 *
 */
void fetch_instruction(void)
{
	int i = 0;

	instruction_t instruction[] = {
		{"push", &push}, {},
		{"pint", &pint}, {},
		{"pall", &pall}, {},
		{NULL, NULL},
	};

	if (global_fd->num_tokens == 0)
	{
		if (strcmp(instruction[i].opcode, global_fd->tokens[0])
				== 0)
		{
			global_fd->instruction->opcode = instruction[i].opcode;
			global_fd->instruction->f = instruction[i].f;
		}
		return;
	}

	invalid_instruction();
}
/**
 * invalid_instruction - function that handles unknown erroe
 */

void invalid_instruction(void)
{
	dprintf(2, "L%d:  unknown instruction %s\n",
			global_fd->lineNum, global_fd->tokens[0]);
	close_stream();
	free_tokens();
	free_global_fd();
	exit(EXIT_FAILURE);
}

/**
 * run_instruction - runs instruction for global_fd
 */

void run_instruction(void)
{
	stack_t *stack = NULL;

	if (global_fd->num_tokens == 0)
		return;

		global_fd->instruction->f(&stack, global_fd->lineNum);
}
