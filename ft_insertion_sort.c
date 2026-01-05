/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/05 20:10:00 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	i;

	printf("=========> Debut du tri...\n");
	if (stack_a->size > 1)
	{
		if ((stack_a->top + 1)->integer < (stack_a->top->integer))
		{
			ft_stack_rotate(stack_a);
		}
		if (stack_a->size > 2)
		{
printf("=========> ...\n");
			ft_stack_push(stack_b, ft_stack_pop(stack_a));
			ft_stack_push(stack_b, ft_stack_pop(stack_a));
			i = 1;
			while (++i < stack_a->size)
			{
				if (stack_a->top->integer > stack_b->top->integer)
				{
					while (stack_a->top->integer > stack_b->last->integer && stack_b->last->integer > stack_b->top->integer)
						ft_stack_reverse_rotate(stack_b);
				}
				else
				{
					while (stack_a->top->integer < stack_b->top->integer && stack_b->top->integer < stack_b->last->integer)
						ft_stack_rotate(stack_b);
				}
				ft_stack_push(stack_b, ft_stack_pop(stack_a));
			}
			while (stack_b->last->integer > stack_b->top->integer)
				ft_stack_reverse_rotate(stack_b);
			i = 0;
			while (++i <= stack_a->size)
				ft_stack_push(stack_b, ft_stack_pop(stack_a));
		}
	}
}
