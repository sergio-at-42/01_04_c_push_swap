/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_insertion_invert.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/24 21:51:45 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_insertion_invert(t_stack *stack, t_list_op	*lst_op)
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
		while (current != first && current->integer > stack->top->integer)
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
