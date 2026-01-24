/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/24 17:31:28 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_insertion(t_stack *stack, t_list_op	*lst_op)
{
	t_element	*next;
	t_element	*first;
	t_element	*current;
	int			i;
// int j;
// t_element *el;

	first = stack->top;
	current = stack->top->next;
	next = current->next;
	i = 2;
	while (i <= stack->size)
	{
		while (current != first && current->integer < stack->top->integer)
		{
			ft_stack_swap(stack, lst_op);
			if (stack->top->next == first)
				first = stack->top;
			else
				ft_stack_reverse_rotate(stack,  lst_op);
		}
		while (stack->top->next != next)
			ft_stack_rotate(stack,  lst_op);
		current = next;
		next = current->next;
		i++;


// printf("Disorder %f\n", ft_stack_disorder(stack));
// if (ft_stack_disorder(stack) < 0.32 && ft_stack_disorder(stack) > 0.28)
// {
// 	el = stack->top;
// 	j = 1;
// 	while (j <= stack->size)
// 	{
// 		printf("%d ", el->integer);
// 		el = el->next;
// 		j++;
// 	}
// 	printf("\n");
// 	printf("\n");
// 	printf("\n");
// }

	}
	ft_stack_rotate(stack,  lst_op);
}
