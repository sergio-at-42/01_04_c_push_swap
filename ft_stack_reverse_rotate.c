/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:49:02 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:50:40 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_reverse_rotate(t_stack *stack, t_list_op *lst_op)
{
	if (stack->size > 1)
	{
		stack->top = stack->top->previous;
		stack->last = stack->last->previous;
		ft_op_add(lst_op, 'i', stack->name);
	}
}
