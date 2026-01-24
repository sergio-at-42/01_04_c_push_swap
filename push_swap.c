/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:26 by Serge             #+#    #+#             */
/*   Updated: 2026/01/24 17:51:44 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_stack_display(t_stack *stack)
{
	t_element	*element;
	int			i;

	element = stack->top;
	i = 1;
	while (i <= stack->size)
	{
		printf("| %d => %d ", element->norme, element->integer);
		element = element->next;
		i++;
	}
		printf("\n");
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_list_op	*lst_op;
	int			error;
	int	i;

	lst_op = ft_op_init();
	stack_a = ft_stack_init('a');
	stack_b = ft_stack_init('b');

	error = ft_push_swap_parser(argc, argv, stack_a, lst_op);
	if (error)
		return (ft_push_swap_error(error));

	if (lst_op->strategy == 's' || (lst_op->strategy == 'a'
		&& stack_a->disorder < 0.2))
			ft_sort_selection(stack_a, stack_b, lst_op);
			// ft_sort_insertion(stack_a, lst_op);
			// ft_sort_bubble(stack_a, lst_op);
			// ft_sort_min_max(stack_a, stack_b, lst_op);
	else if (lst_op->strategy == 'm' || (lst_op->strategy == 'a'
		&& stack_a->disorder >= 0.2 && stack_a->disorder < 0.5))
			ft_sort_min_max(stack_a, stack_b, lst_op);
	else if (lst_op->strategy == 'c' || (lst_op->strategy == 'a'
		&& stack_a->disorder >= 0.5))
			ft_sort_radix(stack_a, stack_b, lst_op);

	// ft_stack_swap_pos(stack_a, lst_op, ft_stack_pos_max(stack_a));

	// ft_stack_swap(stack_a, lst_op);
	// ft_stack_display(stack_a);
	// ft_stack_rotate(stack_a,  lst_op);
	// ft_stack_display(stack_a);
	// ft_stack_swap(stack_a, lst_op);
	// ft_stack_display(stack_a);
	// ft_stack_rotate(stack_a,  lst_op);
	// ft_stack_display(stack_a);
	// ft_stack_swap(stack_a, lst_op);
	// ft_stack_display(stack_a);
	// ft_stack_rotate(stack_a,  lst_op);
	// ft_stack_display(stack_a);
	// ft_stack_swap(stack_a, lst_op);
	// ft_stack_display(stack_a);

	ft_op_disp_lst(lst_op);
	if (lst_op->benchmark)
		ft_push_swap_benchmark(stack_a, lst_op);

	ft_stack_del(stack_a);
	ft_stack_del(stack_b);
	ft_op_del_lst(lst_op);
	return (0);
}
