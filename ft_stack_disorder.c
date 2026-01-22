/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_disorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:55:44 by Serge             #+#    #+#             */
/*   Updated: 2026/01/22 14:46:33 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	ft_stack_disorder(t_stack *stack)
{
	t_element	*element1;
	t_element	*element2;
	float		disorder;
	float		pairs;
	int			i;
	int			j;

	disorder = 0;
	pairs = 0;
	if (stack->size > 1)
	{
		element1 = stack->top;
		i = 1;
		while (i < stack->size)
		{
			element2 = element1->next;
			j = i + 1;
			while (j <= stack->size)
			{
				pairs++;
				if (element1->integer > element2->integer)
					disorder++;
				element2 = element2->next;
				j++;
			}
			element1 = element1->next;
			i++;
		}
		disorder /= pairs;
	}
	return (disorder);
}
