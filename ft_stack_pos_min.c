/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_pos_min.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:17:44 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:39:35 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_pos_min(t_stack *stack)
{
	t_element	*element;
	int			pos;

	element = stack->top;
	pos = 1;
	while (element != stack->min)
	{
		element = element->next;
		pos++;
	}
	return (pos);
}
