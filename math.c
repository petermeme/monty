#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * of the stack.
 * @head: double pointer to the head of the stack
 * @nline: the number of the line in file
 *
 * Return: void
 */
void sub(stack_t **head, unsigned int nline)
{
	stack_t *temp;
	int product;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%u: can't sub, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	product = temp->next->n - temp->n;
	temp->next->n = product;

	*head = temp->next;

	free(temp);
}

/**
 * _div - divides the second top element of the stack by the top element
 * of the stack.
 * @head: double pointer to the head of the stack
 * @nline: the number of the line in file
 *
 * Return: void
 */
void _div(stack_t **head, unsigned int nline)
{
	stack_t *temp;
	int product;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%u: can't div, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	product = temp->next->n / temp->n;
	temp->next->n = product;

	*head = temp->next;

	free(temp);
}

/**
 * mul - multiplies the second top element of the stack with the top element
 * of the stack.
 * @head: double pointer to the head of the stack
 * @nline: the number of the line in file
 *
 * Return: void
 */
void mul(stack_t **head, unsigned int nline)
{
	stack_t *temp;
	int product;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%u: can't mul, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	product = temp->next->n * temp->n;
	temp->next->n = product;

	*head = temp->next;

	free(temp);
}

/**
 * mod - computes the rest of the division of the second top element
 * of the stack by the top element of the stack.
 * @head: double pointer to the head of the stack
 * @nline: the number of the line in file
 *
 * Return: void
 */
void mod(stack_t **head, unsigned int nline)
{
	stack_t *temp;
	int product;

	if (!head || !(*head) || !(*head)->next)
	{
		printf("L%u: can't mod, stack too short\n", nline);
		exit(EXIT_FAILURE);
	}

	temp = *head;

	product = temp->next->n % temp->n;
	temp->next->n = product;

	*head = temp->next;

	free(temp);
}
