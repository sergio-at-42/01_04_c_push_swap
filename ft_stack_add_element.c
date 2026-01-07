/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_add_element.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:05:31 by Serge             #+#    #+#             */
/*   Updated: 2026/01/06 16:05:35 by Serge            ###   ########.fr       */
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
	element->previous = NULL;
	element->next = stack->top;
	if (stack->top)
		stack->top->previous = element;
	else
		stack->last = element;
	stack->top = element;
	stack->size++;
	return (element);
}
