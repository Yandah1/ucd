#include "monty.h."

/**
 * fetch_instruction - set instructions
 *
 */
void fetch_instruction(void)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", &push},  {"pop", &pop},
		{"pint", &pint}, {"swap", &swap},
		{"nop", &nop},  {"add", &add},
		{"pall", &pall}, {"sub", &sub},
		{"div", &div}, {"mul", &mul},
		{"rotl", &rotl}, {"rotr", &rotr},
		{"stack", &stack}, {"queue", &queue},
		{"pstr", &pstr}, {"pchar", &pchar},
		{"mod", &mod},
		{NULL, NULL},
	};

	if (argument->num_tokens == 0)
	{
		if (strcmp(instructions[i].opcode, argument->tokens[0])
				== 0)
		{
			argument->instruction->opcode = instruction[i].opcode;
			argument->instruction->f = instruction[i].f;
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
			argument->lineNum, argument->tokesns[0]);
	close_stream();
	free_tokens();
	free_global_fd();
	exit(EXIT_FAILURE);
}

