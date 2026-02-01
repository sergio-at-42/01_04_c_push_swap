/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bucket_sqrt.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/31 20:41:24 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_square_root(t_stack *stack_a)
{
	int	sqrt;

	sqrt = 0;
	while (sqrt * sqrt <= stack_a->size)
		sqrt++;
	sqrt--;
	return (sqrt);
}

static	void	ft_sort(t_stack *stack_a, t_stack *stack_b, t_list_op *lst_op)
{
	while (stack_b->size > 0)
	{
		ft_stack_swap_pos(stack_b, lst_op, ft_stack_pos_max(stack_b));
		ft_stack_push(stack_b, stack_a, lst_op);
	}
}

void	ft_sort_bucket(t_stack *sa, t_stack *sb, t_list_op *lst_op)
{
	t_element	*top;
	int			buck;
	int			buck_max;

	top = sa->top;
	buck = ft_square_root(sa);
	buck_max = sa->size;
	while (buck_max > 0)
	{
		if (buck_max < buck)
			buck = buck_max;
		while (sb->size < buck)
		{
			if (sa->top->norme > buck_max - buck && sa->top->norme <= buck_max)
				ft_stack_push(sa, sb, lst_op);
			else
				ft_stack_reverse_rotate(sa, lst_op);
		}
		while (sa->top != top && buck_max - buck != sa->size && sa->size != 0)
			ft_stack_rotate(sa, lst_op);
		ft_sort(sa, sb, lst_op);
		top = sa->top;
		buck_max -= buck;
		if (buck_max != 0)
			ft_stack_reverse_rotate(sa, lst_op);
	}
}
