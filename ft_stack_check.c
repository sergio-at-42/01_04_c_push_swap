/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:55:44 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:38:03 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_check(t_stack *stack)
{
	t_element	*element;
	int			sort_ok;
	int			i;

	sort_ok = 1;
	if (stack->size > 1)
	{
		element = stack->top->next;
		i = 2;
		while (i <= stack->size)
		{
			if (element->previous->integer > element->integer)
				sort_ok = 0;
			element = element->next;
			i++;
		}
	}
	return (sort_ok);
}
