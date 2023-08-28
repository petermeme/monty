#include <stdio.h>
#include "monty.h"

stack_t **global_head = NULL;

/**
 * main - the root of the project
 * @argc: how many arguments were passed to a program
 * @argv: arguments vector
 *
 * Return: on scuccess, always EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	stack_t *head;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	head = NULL;
	global_head = &head;

	read_file(argv[1], &head);

	atexit(global_free);

	exit(EXIT_SUCCESS);
}


/**
 * read_file - reads a file
 * @stack: pointer to file descriptor
 * @file: pathname to file
 * Return: void
 */

void read_file(char *file, stack_t **stack)
{
	size_t len;
	int read;
	unsigned int num = 0;
	char *line;
	FILE *fd;
	char *command;

	fd = fopen(file, "r");
	if (!fd)
	{
		printf("Error: Can't open file %s\n", file);
		exit(EXIT_FAILURE);
	}
	puts ("enter text");
	line = (char *) malloc(len + 1);
	read = getline(&line, &len, fd);

	if (read == -1)
	{
		command = strtok(line, delims);
		num++;
	}
		if (command)
		{
			parse_command(stack, command, num);
		}

	if (line)
	{
		free(line);
	}

	fclose(fd);
}
