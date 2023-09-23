#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "monty.h"

void free_global_fd(void);
/**
 * get_failed_stream - Display an error message and exit the program.
 * @fileName: The name of the file that caused the error.
 *
 */

void get_failed_stream(char *fileName)
{
	fprintf(stderr, "Error: Failed to open file %s\n", fileName);
	free_global_fd();
	exit(EXIT_FAILURE);
}

/**
 * get_stream - open file in read-only mode
 * @fileName: the name of the file to open
 *
 * If successful, the stream is stored in the
 * global_fd structure.
 */
void get_stream(char *fileName)
{
	int fileD;

	fileD = open(fileName, O_RDONLY);
	if (fileD == -1)
	{
		get_failed_stream(fileName);
	}

	global_fd->stream = fdopen(fileD, "r");
	if (global_fd->stream == NULL)
	{
		close(fileD);
		get_failed_stream(fileName);
	}
}
/**
 * close_stream - Closes stream
 *
 */
void close_stream(void)
{
	if (global_fd->stream == NULL)
		return;

	fclose(global_fd->stream);
	global_fd->stream = NULL;
}
