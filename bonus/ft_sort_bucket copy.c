/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bucket.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/31 20:43:09 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_nb_bucket(t_stack *stack_a, int buck)
{
	int	i;

	i = stack_a->size / buck;
	if (stack_a->size % buck != 0)
		i++;
	return (i);
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
	int			i;

	top = sa->top;
	buck = 50;
	i = ft_nb_bucket(sa, buck);
	while (i > 0)
	{
		if (i == 1 && sa->size % buck != 0)
			buck = sa->size % buck;
		while (sb->size < buck)
		{
			if (sa->top->norme > buck * (i - 1) && sa->top->norme <= buck * i)
				ft_stack_push(sa, sb, lst_op);
			else
				ft_stack_reverse_rotate(sa, lst_op);
		}
		while (sa->top != top && i != sa->size / buck + 1)
			ft_stack_rotate(sa, lst_op);
		ft_sort(sa, sb, lst_op);
		top = sa->top;
		if (--i != 0)
			ft_stack_reverse_rotate(sa, lst_op);
	}
}
