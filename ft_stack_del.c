/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_del.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfuente <stfuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 16:03:56 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 17:16:49 by stfuente         ###   ########.fr       */
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
