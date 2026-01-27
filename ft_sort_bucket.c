/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/27 21:12:56 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bucket(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op)
{
	t_element	*top;
	int			bucket_size;
	int			i;

	top = stack_a->top;
	bucket_size = 50;
	i = stack_a->size / bucket_size;
	if (stack_a->size % bucket_size != 0)
		i++;
	while (i > 0)
	{
		if (i == 1 && stack_a->size % bucket_size != 0)
			bucket_size = stack_a->size % bucket_size;
		while (stack_b->size < bucket_size)
		{
			if (stack_a->top->norme > bucket_size * (i - 1) && stack_a->top->norme <= bucket_size * (i))
				ft_stack_push(stack_a, stack_b, lst_op);
			else
				ft_stack_reverse_rotate(stack_a, lst_op);
		}
		if (i != stack_a->size / bucket_size + 1)
			while (stack_a->top != top)
				ft_stack_rotate(stack_a, lst_op);
		while (stack_b->size > 0)
		{
			ft_stack_swap_pos(stack_b, lst_op, ft_stack_pos_max(stack_b));
			ft_stack_push(stack_b, stack_a, lst_op);
		}
		top = stack_a->top;
		if (i != 1)
			ft_stack_reverse_rotate(stack_a, lst_op);
		i--;
	}
}
