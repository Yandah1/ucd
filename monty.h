#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <ctype.h>

/*
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct fd - Hold files variables
 * @stream: Pointer to the file stream
 * @line: Pointer to the line data
 */
typedef struct fd
{
	FILE *stream;
	char *line;
	char **tokens;
	int num_tokens;
	unsigned int lineNum;
	instruction_t *instPtr;

} Global_d;

extern Global_d *global_fd;

void free_global_fd(void);
void malloc_failed(void);
void initialize_global_fd(void);
void get_failed_stream(char *fileName);
void get_stream(char *fileName);
void validate_arguments(int argc);





/* main */
int main(int argc, char **arg);

#endif /* MONTY_H */