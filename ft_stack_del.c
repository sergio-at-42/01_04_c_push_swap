/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:56 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 20:56:05 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_del(t_stack *stack)
{
	t_element	*element;
	int			i;

	i = 1;
	while (i <= stack->size)
	{
		element = stack->top;
		stack->top = element->next;
		free(element);
		i++;
	}
	free(stack);
}
