/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:05:31 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:56:22 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_stack_add_element(t_stack *stack, int integer)
{
	t_element	*element;

	element = (t_element *)malloc(sizeof(t_element));
	if (!element)
		return (NULL);
	element->integer = integer;
	element->norme = 0;
	if (stack->last)
	{
		element->previous = stack->last;
		element->next = stack->top;
		stack->top->previous = element;
		stack->last->next = element;
		if (integer < stack->min->integer)
			stack->min = element;
		if (integer > stack->max->integer)
			stack->max = element;
	}
	else
	{
		element->previous = element;
		element->next = element;
		stack->top = element;
		stack->min = element;
		stack->max = element;
	}
	stack->last = element;
	stack->size++;
	return (element);
}
