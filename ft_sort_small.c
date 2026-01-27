/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/27 20:29:26 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_small(t_stack *stack, t_list_op *lst_op)
{
	if (stack->size <= 3)
	{
		while (ft_stack_disorder(stack))
		{
			if ((stack->top->norme == 2 && stack->top->next->norme == 1)
				|| (stack->top->norme == 3 && stack->top->next->norme == 2)
				|| (stack->top->norme == 1))
					ft_stack_swap(stack, lst_op);
			else if (stack->top->norme == 2)
				ft_stack_reverse_rotate(stack, lst_op);
			else
				ft_stack_rotate(stack, lst_op);
		}
	}
}
