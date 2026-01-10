/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_swap_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 13:17:44 by Serge             #+#    #+#             */
/*   Updated: 2026/01/10 15:39:51 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_swap_pos(t_stack *stack, t_list_op *lst_op, int pos)
{
	int	i;

	if (pos > 1)
	{
		i = 1;
		if (pos <= ((stack->size / 2) + (stack->size % 2)))
		{
			while (i < pos)
			{
				ft_stack_rotate(stack, lst_op);
				i++;
			}
		}
		else
		{
			while (i <= (stack->size - pos + 1))
			{
				ft_stack_reverse_rotate(stack, lst_op);
				i++;
			}
		}
	}
}
