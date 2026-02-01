/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_norme.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/10 16:00:47 by Serge             #+#    #+#             */
/*   Updated: 2026/01/30 17:53:43 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_sort_stack_clone(t_element **stack_clone, int size)
{
	t_element	*swap;
	int			i;
	int			j;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
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
}

void	ft_stack_norme(t_stack *stack)
{
	t_element	**stack_clone;
	t_element	*element;
	int			i;

	stack_clone = (t_element **)malloc(sizeof(t_element *) * stack->size);
	element = stack->top;
	i = 0;
	while (i < stack->size)
	{
		stack_clone[i] = element;
		element = element->next;
		i++;
	}
	ft_sort_stack_clone(stack_clone, stack->size);
	i = 1;
	while (i <= stack->size)
	{
		stack_clone[i - 1]->norme = i;
		i++;
	}
	free(stack_clone);
}
