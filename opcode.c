#include "monty.h"

/**
 * push - adds and pushes an element to the stack
 * @head: head to the linked list
 * @nline: the number of line of the instruction
 *
 * Return: no return
 */
void push(stack_t **head, unsigned int nline)
{
	stack_t *stack;
	char *num = 0;

	num = strtok(NULL, delims);
	stack = malloc(sizeof(stack_t));
	if (stack == NULL)
{
	printf("Error: malloc failed\n");
	exit(EXIT_FAILURE);
}
	if (num == NULL)
{
	fprintf(stderr, "L%d: usage: push integer", nline);
	exit(EXIT_FAILURE);
}
	stack->n = atoi(num);
	stack->prev = NULL;
	stack->next = *head;
}

/**
 * pall - prints all the values on the stack, from the top of the stack
 * @head: head to the linked list
 * @nline: the number of line ofthe instruction
 * Return: no return
 */
void pall(stack_t **head, unsigned int nline)
{
	stack_t *tmp = *head;
	(void)nline;

	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - prints the value at the top of the stack, followed by a new line.
 * @head: head to the linked list
 * @nline: the number of line ofthe instruction
 * Return: no return
 */
void pint(stack_t **head, unsigned int nline)
{
	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pint, stack empty\n", nline);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}

/**
 * pop - removes the top element of the stack
 * @head: head to the linked list
 * @nline: the number of line ofthe instruction
 * Return: no return
 */
void pop(stack_t **head, unsigned int nline)
{
	stack_t *tmp;

	if (head == NULL || *head == NULL)
	{
		printf("L%u: can't pop an empty stack\n", nline);
		exit(EXIT_FAILURE);
	}

	tmp = *head;
	*head = (*head)->next;

	free(tmp);
}

/**
 * swap - swaps the top two elements of the stack
 * @head: head to the linked list
 * @nline: the number of line ofthe instruction
 * Return: no return
 */
void swap(stack_t **head, unsigned int nline)
{
	stack_t *tmp;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%u: can't swap, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}
