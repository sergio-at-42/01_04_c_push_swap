/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:46:01 by Serge             #+#    #+#             */
/*   Updated: 2026/01/05 17:46:14 by Serge            ###   ########.fr       */
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
	if (stack->size > 1)
		stack->top->previous = NULL;
	else
		stack->last = NULL;
	stack->size--;
	free(top);
	top = NULL;
	return (element);
}
