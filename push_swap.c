/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:26 by Serge             #+#    #+#             */
/*   Updated: 2026/01/20 19:41:24 by Serge            ###   ########.fr       */
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

int	ft_return_error(void)
{
	write(2, "Error\n", 6);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_element	*element;
	t_list_op	*lst_op;
	int		i;

	lst_op = ft_op_init();
	stack_a = ft_stack_init('a');
	stack_b = ft_stack_init('b');
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
			ft_stack_add_element(stack_a, ft_atoi(argv[i]));
	}

	printf("Disorder de la stack avant : %f\n", ft_stack_disorder(stack_a));

	ft_stack_norme(stack_a);
	
	ft_benchmark(stack_a, lst_op);

	// ft_sort_insertion(stack_a, lst_op);
	// ft_stack_display(stack_a);

	// ft_sort_selection(stack_a, stack_b, lst_op);
	// ft_stack_display(stack_a);

	// ft_sort_bubble(stack_a, lst_op);
	// ft_stack_display(stack_a);

	ft_sort_min_max(stack_a, stack_b, lst_op);
	ft_stack_display(stack_a);

	// ft_sort_radix(stack_a, lst_op);
	// ft_stack_display(stack_a);

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

	printf("\n");
	printf("stack A ->   size : %d   min : %d   max : %d\n", stack_a->size, stack_a->min->integer, stack_a->max->integer);
	printf("Tri de la stack : %s\n", ft_stack_check(stack_a)?"OK":"NOK");
	printf("Disorder de la stack apres : %f\n", ft_stack_disorder(stack_a));
	printf("Nombre d'operations : %d\n", lst_op->nb);
	printf("\n");

	ft_benchmark(stack_a, lst_op);

	ft_stack_del(stack_a);
	ft_stack_del(stack_b);
	ft_op_del_lst(lst_op);
	return (0);
}
