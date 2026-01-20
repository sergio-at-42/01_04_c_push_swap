/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_bubble.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/16 16:53:22 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_bubble(t_stack *stack, t_list_op *lst_op)
{
	t_element	*first;
	t_element	*last;

	if (stack->size > 1)
	{
		if (stack->top->integer > stack->top->next->integer)
			ft_stack_swap(stack, lst_op);
		first = stack->top;
		last = stack->last;
		while (first->next != last)
		{
			while (stack->top != last)
			{
				if (stack->top->integer > stack->top->next->integer)
				{
					if (stack->top == first)
						first = stack->top->next;
					if (stack->top->next == last)
						last = stack->top;
					ft_stack_swap(stack, lst_op);
				}
				ft_stack_rotate(stack, lst_op);
			}
			last = last->previous;
			ft_stack_reverse_rotate(stack, lst_op);
			while (stack->top != first)
			{
				ft_stack_reverse_rotate(stack, lst_op);
				if (stack->top->integer > stack->top->next->integer)
				{
					if (stack->top == first)
						first = stack->top->next;
					if (stack->top->next == last)
						last = stack->top;
					ft_stack_swap(stack, lst_op);
				}
			}
			if (first->next != last)
				first = first->next;
		}
		ft_stack_swap_pos(stack, lst_op, ft_stack_pos_min(stack));
	}
}
