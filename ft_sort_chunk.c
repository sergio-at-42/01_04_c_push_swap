/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_chunk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/24 20:41:38 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_chunk(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op)
{
	int	nb_element;

	nb_element = stack_a->size;
	while (stack_a->size > nb_element / 2)
	{
		if (stack_a->top->norme <= nb_element / 2)
			ft_stack_push(stack_a, stack_b, lst_op);
		else
			ft_stack_rotate(stack_a, lst_op);
	}
	ft_sort_insertion(stack_a, lst_op);
	ft_sort_insertion_invert(stack_b, lst_op);
	while (stack_b->size)
		ft_stack_push(stack_b, stack_a, lst_op);
}
