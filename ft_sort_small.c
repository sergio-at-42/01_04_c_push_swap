/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 20:03:20 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stack *stack_a, t_stack *stack_b, t_list_op *op)
{
	if (stack_a->size <= 5)
	{
		op->strategy = 't';
		while (stack_a->size > 3)
		{
			ft_stack_swap_pos(stack_a, op, ft_stack_pos_min(stack_a));
			ft_stack_push(stack_a, stack_b, op);
		}
		ft_stack_norme(stack_a);
		while (ft_stack_disorder(stack_a))
		{
			if ((stack_a->top->norme == 2 && stack_a->top->next->norme == 1)
				|| (stack_a->top->norme == 3 && stack_a->top->next->norme == 2)
				|| (stack_a->top->norme == 1))
				ft_stack_swap(stack_a, op);
			else if (stack_a->top->norme == 2)
				ft_stack_reverse_rotate(stack_a, op);
			else
				ft_stack_rotate(stack_a, op);
		}
		while (stack_b->size > 0)
			ft_stack_push(stack_b, stack_a, op);
	}
}
