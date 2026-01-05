/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:26 by Serge             #+#    #+#             */
/*   Updated: 2026/01/03 18:47:54 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack()
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->size = 0;
	stack->top = NULL;
	stack->last = NULL;
	return (stack);
}

t_element	*push(t_stack *stack, int integer)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->integer = integer;
	if (stack->top == NULL)
	{
		stack->top = element;
		element->previous = NULL;
	}
	else
		element->previous = stack->last;
	element->next = NULL;
	stack->last = element;
	stack->size++;
	return (element);
}

int	pop(t_stack *stack)
{
	int			element;
	t_element	*top;

	top = stack->top;
	element = top->integer;
	stack->top = top->next;
	if (stack->size > 1)
		stack->top->previous = NULL;
	else
		stack->last = NULL;
	stack->size--;
	free(top);
	top = NULL;
	return(element);
}

void	swap(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->top = stack->top->next;
		stack->top->previous->previous = stack->top;
		stack->top->previous->next = stack->top->next;
		stack->top->next = stack->top->previous;
		stack->top->previous = NULL;
	}
}

void	rotate(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->last->next = stack->top;
		stack->top->previous = stack->last;
		stack->last = stack->top;
		stack->top = stack->top->next;
		stack->top->previous = NULL;
		stack->last->next = NULL;
	}
}

void	reverse_rotate(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->top->previous = stack->last;
		stack->last->next = stack->top;
		stack->top = stack->last;
		stack->last = stack->top->previous;
		stack->top->previous = NULL;
		stack->last->next = NULL;
	}
}
