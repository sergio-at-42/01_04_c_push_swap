/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:41:45 by Serge            ###   ########.fr       */
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
	// t_element	*element;
	// int			i;

	while (stack_a->size > 1)
	{
		ft_stack_swap_pos(stack_a, lst_op, ft_stack_pos_min(stack_a));
		ft_stack_push(stack_a, stack_b, lst_op);
	}

	// while (stack_a->size > 1)
	// {
	// 	element = stack_a->top;
	// 	i = 0;
	// 	while (element != stack_a->min)
	// 	{
	// 		element = element->next;
	// 		i++;
	// 	}
	// 	i = i / (stack_a->size / 2);
	// 	while (stack_a->top != stack_a->min)
	// 		if (i)
	// 			ft_stack_reverse_rotate(stack_a, lst_op);
	// 		else
	// 			ft_stack_rotate(stack_a, lst_op);
	// 	ft_stack_push(stack_a, stack_b, lst_op);
	// }
	// while (stack_b->last->integer >= stack_b->top->integer)
	// 	ft_stack_reverse_rotate(stack_b, lst_op);
	while (stack_b->size)
		ft_stack_push(stack_b, stack_a, lst_op);
}
