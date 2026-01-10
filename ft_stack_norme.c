/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:00:47 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 20:56:18 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_norme(t_stack *stack)
{
	t_element	**stack_clone;
	t_element	*element;
	t_element	*swap;
	int			i;
	int			j;

	stack_clone = (t_element **)malloc(sizeof(t_element *) * stack->size);
	element = stack->top;
	i = 0;
	while (i < stack->size)
	{
		stack_clone[i] = element;
		element = element->next;
		i++;
	}
	i = 0;
	while (i < stack->size - 1)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack_clone[i]->integer > stack_clone[j]->integer)
			{
				swap = stack_clone[j];
				stack_clone[j] = stack_clone[i];
				stack_clone[i] = swap;
			}
			j++;
		}
		i++;		
	}
	i = 1;
	while (i <= stack->size)
	{
		stack_clone[i - 1]->norme = i;
		i++;
	}
	free(stack_clone);
}
