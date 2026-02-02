/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:26 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 20:20:24 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_sort(t_stack *stack_a, t_stack *stack_b, t_list_op *lst_op)
{
	if (stack_a->disorder != 0)
	{
		if (lst_op->strategy == 'a' && stack_a->size <= 5)
			ft_sort_small(stack_a, stack_b, lst_op);
		else if (lst_op->strategy == 's' || (lst_op->strategy == 'a'
				&& stack_a->disorder < 0.2))
			ft_sort_selection(stack_a, stack_b, lst_op);
		else if (lst_op->strategy == 'm' || (lst_op->strategy == 'a'
				&& stack_a->disorder >= 0.2 && stack_a->disorder < 0.5))
			ft_sort_bucket(stack_a, stack_b, lst_op);
		else if (lst_op->strategy == 'c' || (lst_op->strategy == 'a'
				&& stack_a->disorder >= 0.5))
			ft_sort_radix(stack_a, stack_b, lst_op);
	}
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list_op	*lst_op;
	int			error;

	lst_op = ft_op_init();
	stack_a = ft_stack_init('a');
	stack_b = ft_stack_init('b');
	error = ft_ps_parser(argc, argv, stack_a, lst_op);
	if (!error)
	{
		ft_stack_sort(stack_a, stack_b, lst_op);
		ft_op_disp_lst(lst_op);
		if (lst_op->benchmark)
			ft_ps_benchmark(stack_a, lst_op);
	}
	else
		ft_ps_error(error);
	ft_stack_del(stack_a);
	ft_stack_del(stack_b);
	ft_op_del_lst(lst_op);
	return (error);
}
