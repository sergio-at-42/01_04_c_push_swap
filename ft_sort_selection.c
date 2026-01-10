/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:49:22 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	display_stack(t_stack *stack)
// {
// 	int			i;
// 	t_element	*element;

// 	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvstack %c   <===>   stack->min\n", stack->name, stack->min);
// 	i = 0;
// 	element = stack->top;
// 	while (i < stack->size)
// 	{
// 		printf("   %d", element->integer);
// 		i++;
// 		element = element->next;
// 	}
// 	printf("\n");
// 	printf("size : %d\n", stack->size);
// 	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
// }

void	ft_sort_selection(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op)
{
	while (stack_a->size > 1)
	{
		ft_stack_swap_pos(stack_a, lst_op, ft_stack_pos_min(stack_a));
		ft_stack_push(stack_a, stack_b, lst_op);
	}
	while (stack_b->size)
		ft_stack_push(stack_b, stack_a, lst_op);
}
