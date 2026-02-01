/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_disorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:55:44 by Serge             #+#    #+#             */
/*   Updated: 2026/01/30 18:25:23 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_nb_pairs(int size)
{
	int	i;
	int	j;
	int	pairs;

	pairs = 0;
	i = 1;
	while (i < size)
	{
		j = i + 1;
		while (j <= size)
		{
			pairs++;
			j++;
		}
		i++;
	}
	return (pairs);
}

float	ft_stack_disorder(t_stack *stack)
{
	t_element	*element1;
	t_element	*element2;
	float		disorder;
	int			i;
	int			j;

	disorder = 0;
	if (stack->size > 1)
	{
		element1 = stack->top;
		i = 0;
		while (++i < stack->size)
		{
			element2 = element1->next;
			j = i;
			while (++j <= stack->size)
			{
				if (element1->integer > element2->integer)
					disorder++;
				element2 = element2->next;
			}
			element1 = element1->next;
		}
	}
	return (disorder / ft_nb_pairs(stack->size));
}
