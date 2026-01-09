/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:25:48 by Serge             #+#    #+#             */
/*   Updated: 2026/01/08 13:26:35 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_stack_max(t_stack *stack)
{
	t_element	*element;
	t_element	*max;

	element = stack->top;
	max = stack->top;
	while (element)
	{
		if (element->integer > max->integer)
			max = element;
		element = element->next;
	}
	stack->max = max;
	return (max);
}
