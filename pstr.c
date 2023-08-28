#include "monty.h"

/**
 * pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: double pointer to the head of the stack
 * @nline: the number of a line of the file
 *
 * Return: void
 */
void pstr(stack_t **head, unsigned int nline)
{
	stack_t *h;
	(void)nline;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
}
