#include <ctype.h>
#include "monty.h"

/**
 * pchar - prints the char at the top of the stack, followed by a new line.
 * @head: double pointer to the head of the stack
 * @nline: the number of the line in file
 *
 * Return: void
 */
void pchar(stack_t **head, unsigned int nline)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", nline);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", nline);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
