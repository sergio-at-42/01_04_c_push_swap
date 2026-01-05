/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:49:02 by Serge             #+#    #+#             */
/*   Updated: 2026/01/05 17:49:07 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_reverse_rotate(t_stack *stack)
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
