/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/26 17:13:02 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bucket(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op)
{
	t_element	*top;
	int	bucket_size;
	int	i;

	top = stack_a->top;
	bucket_size = stack_a->size / 10;
	i = 9;
	while (i >= 0)
	{
		while (stack_b->size < bucket_size)
		{
			if (stack_a->top->norme > bucket_size * i && stack_a->top->norme <= bucket_size * (i + 1))
				ft_stack_push(stack_a, stack_b, lst_op);
			else
				ft_stack_reverse_rotate(stack_a, lst_op);
		}
		if (i != 9)
			while (stack_a->top != top)
				ft_stack_rotate(stack_a, lst_op);
		while (stack_b->size > 0)
		{
			ft_stack_swap_pos(stack_b, lst_op, ft_stack_pos_max(stack_b));
			ft_stack_push(stack_b, stack_a, lst_op);
		}
		top = stack_a->top;
		if (i)
			ft_stack_reverse_rotate(stack_a, lst_op);
		i--;
	}
}
