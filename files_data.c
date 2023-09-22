#include "monty.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * initialize_global_fd - Initializes the global_file_data struct.
 *
 * This function allocates memory for struct and sets its members.
 * If the allocation fails, it frees the file pointer and
 * exits with a failure status.
 */
void initialize_global_fd(void)
{
	global_fd = malloc(sizeof(Global_d));
	if (global_fd == NULL)
	{
		malloc_failed();
	}

	global_fd->instruction = malloc(sizeof(instruction_t));
	if (global_fd->instruction == NULL)
	{
		malloc_failed();
	}

	global_fd->stream = NULL;
	global_fd->line = NULL;
	global_fd->num_tokens = 0;
	global_fd->lineNum = 0;
}
