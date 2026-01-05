/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:39:26 by Serge             #+#    #+#             */
/*   Updated: 2026/01/05 20:07:47 by Serge            ###   ########.fr       */
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
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	stack_a = ft_stack_init();
	stack_b = ft_stack_init();
	if (argc > 1)
	{
		i = 0;
		while (++i < argc)
			printf("%d\n", ft_stack_push(stack_a, ft_atoi(argv[i]))->integer);
	}
	printf("-----------------------------------------------------------------------------------------\n");
	ft_insertion_sort(stack_a, stack_b);
	i = -1;
	while (++i < stack_a->size)
		printf("%d\n", (stack_a->top + i)->integer);
	return (0);
}
