/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:26 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 20:51:47 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_stack_norme(stack_a);
	
	// ft_sort_insertion(stack_a, stack_b, lst_op);

	ft_sort_selection(stack_a, stack_b, lst_op);

	// ft_stack_swap_pos(stack_a, lst_op, ft_stack_pos_max(stack_a));
	element = stack_a->top;
	i = 1;
	while (i <= stack_a->size)
	{
		printf("   %d => %d", element->norme, element->integer);
		element = element->next;
		i++;
	}
		printf("\n");

	printf("stack A ->   size : %d   min : %d   max : %d\n", stack_a->size, stack_a->min->integer, stack_a->max->integer);
	printf("Tri de la stack : %s\n", ft_stack_check(stack_a)?"OK":"NOK");
	printf("Nombre d'operations : %d\n", lst_op->nb);

	ft_stack_del(stack_a);
	ft_stack_del(stack_b);
	ft_op_del(lst_op);
	return (0);
}
