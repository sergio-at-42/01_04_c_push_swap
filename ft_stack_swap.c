/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:47:10 by Serge             #+#    #+#             */
/*   Updated: 2026/01/13 15:53:58 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap(t_stack *stack, t_list_op	*lst_op)
{
	t_element	*swap_next;

	if (stack->size > 1)
	{
		swap_next = stack->top->next->next;
		stack->top = stack->top->next;
		stack->top->next = stack->top->previous;
		stack->top->previous = stack->last;
		stack->top->next->previous = stack->top;
		stack->top->next->next = swap_next;
		stack->last->next = stack->top;
		swap_next->previous = stack->top->next;
		ft_op_add(lst_op, 's', stack->name);
	}
}
