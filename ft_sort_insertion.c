/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/13 16:49:30 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	display_stack(t_stack *stack)
// {
// 	int			i;
// 	t_element	*element;

// 	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
// 	element = stack->top;
// 	i = 0;
// 	while (i < stack->size)
// 	{
// 		printf("   %d", element->integer);
// 		element = element->next;
// 		i++;
// 	}
// 	printf("\n");
// 	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
// }

void	ft_sort_insertion(t_stack *stack, t_list_op	*lst_op)
{
	t_element	*next;
	t_element	*first;
	t_element	*current;
	int			i;

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
	}
	ft_stack_rotate(stack,  lst_op);
}
