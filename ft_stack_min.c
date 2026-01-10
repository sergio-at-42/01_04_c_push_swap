/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_min.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:17:44 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:14:58 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_stack_min(t_stack *stack)
{
	t_element	*element;
	t_element	*min;
	int	i;

	element = stack->top;
	i = 0;
	min = element;
	while (i < stack->size)
	{
		if (element->integer < min->integer)
			min = element;
		i++;
		element = element->next;
	}
	stack->min = min;
	return (min);
}
