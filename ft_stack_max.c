/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_max.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:25:48 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:32:35 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*ft_stack_max(t_stack *stack)
{
	t_element	*element;
	t_element	*max;
	int	i;

	element = stack->top;
	i = 0;
	max = element;
	while (i < stack->size)
	{
		if (element->integer > max->integer)
			max = element;
		i++;
		element = element->next;
	}
	stack->max = max;
	return (max);
}
