/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:44:17 by Serge             #+#    #+#             */
/*   Updated: 2026/01/26 16:06:14 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_push(t_stack *stack_out, t_stack *stack_in, t_list_op *lst_op)
{
	t_element	*element_push;

	if (stack_out->size > 0)
	{
		element_push = stack_out->top;
		stack_out->size--;
		if (stack_out->size == 0)
		{
			stack_out->top = NULL;
			stack_out->last = NULL;
		}
		else
		{
			stack_out->top = stack_out->top->next;
			stack_out->top->previous = stack_out->last;
			stack_out->last->next = stack_out->top;
		}
		if (stack_in->size == 0)
		{
			stack_in->top = element_push;
			stack_in->last = element_push;
		}
		else
		{
			stack_in->top->previous = element_push;
			stack_in->last->next = element_push;
		}
		element_push->previous = stack_in->last;
		element_push->next = stack_in->top;
		stack_in->top = element_push;
		stack_in->size++;
		if (stack_out->min == element_push)
			ft_stack_min(stack_out);
		if (stack_out->max == element_push)
			ft_stack_max(stack_out);
		if (!stack_in->min || element_push->integer < stack_in->min->integer)
			stack_in->min = element_push;
		if (!stack_in->max || element_push->integer > stack_in->max->integer)
			stack_in->max = element_push;
		ft_op_add(lst_op, 'p', stack_in->name);
	}
}
