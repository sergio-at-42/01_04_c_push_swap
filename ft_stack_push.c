/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:17 by Serge             #+#    #+#             */
/*   Updated: 2026/01/05 17:44:35 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_stack_push(t_stack *stack, int integer)
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
