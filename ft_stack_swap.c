/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:47:10 by Serge             #+#    #+#             */
/*   Updated: 2026/01/05 17:47:14 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack *stack)
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
