/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:46:01 by Serge             #+#    #+#             */
/*   Updated: 2026/01/06 14:48:15 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_pop(t_stack *stack)
{
	int			element;
	t_element	*top;

	top = stack->top;
	element = top->integer;
	stack->top = top->next;
	if (stack->top == NULL)
		stack->last = NULL;
	else
		stack->top->previous = NULL;
	stack->size--;
	free(top);
	top = NULL;
	return (element);
}
