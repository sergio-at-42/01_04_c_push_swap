/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bucket_en-cours.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/31 20:17:33 by Serge            ###   ########.fr       */
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

// static int	ft_nb_bucket(t_stack *stack_a, int buck)
// {
// 	int	i;

// 	i = stack_a->size / buck;
// 	if (stack_a->size % buck != 0)
// 		i++;
// 	return (i);
// }

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
	// int			i;
	int			buck_max;

	top = sa->top;
	// buck = 50;
	buck = ft_square_root(sa);
	// i = ft_nb_bucket(sa, buck);
	buck_max = sa->size;
	// while (i > 0)
	while (buck_max > 0)
	{
		// if (i == 1 && sa->size % buck != 0)
		// 	buck = sa->size % buck;
		if (buck_max < buck)
			buck_max = buck;
		while (sb->size < buck)
		{
			if (sa->top->norme > buck_max - buck && sa->top->norme <= buck_max)
				ft_stack_push(sa, sb, lst_op);
			else
				ft_stack_reverse_rotate(sa, lst_op);
		}
printf("sb %d   buck_max %d   buck %d    buck_max - buck %d\n", sb->size, buck_max, buck, buck_max - buck);

		while (sa->top != top && buck_max != sa->size)
			ft_stack_rotate(sa, lst_op);
		ft_sort(sa, sb, lst_op);
		top = sa->top;
		buck_max -= buck;
		if (--buck_max != 0)
			ft_stack_reverse_rotate(sa, lst_op);
	}
}
