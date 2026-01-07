/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:48:06 by Serge             #+#    #+#             */
/*   Updated: 2026/01/07 17:28:46 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rotate(t_stack *stack, t_list_op *lst_op)
{
	if (stack->size > 1)
	{
		stack->last->next = stack->top;
		stack->top->previous = stack->last;
		stack->last = stack->top;
		stack->top = stack->top->next;
		stack->top->previous = NULL;
		stack->last->next = NULL;
		ft_op_add(lst_op, 'r', stack->name);
	}
}
