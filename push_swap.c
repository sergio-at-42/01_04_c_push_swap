/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:26 by Serge             #+#    #+#             */
/*   Updated: 2026/01/07 18:49:05 by Serge            ###   ########.fr       */
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
	ft_insertion_sort(stack_a, stack_b, lst_op);
	element = stack_a->top;
	while (element)
	{
		printf("%d\n", element->integer);
		element = element->next;
	}
	printf("Tri de la stack : %s\n", ft_stack_check(stack_a)?"OK":"NOK");
	printf("Nombre d'operations : %d\n", lst_op->nb);
	while (stack_a->size > 0)
		ft_stack_del_element(stack_a);
	free(stack_a);
	while (stack_b->size > 0)
		ft_stack_del_element(stack_b);
	free(stack_b);
	return (0);
}
