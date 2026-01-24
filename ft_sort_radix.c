/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/24 17:20:32 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	ft_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	result = 1;
	while (power > 0)
	{
		result = nb * result;
		power--;
	}
	return (result);
}

static int	ft_nb_bit(int num)
{
	int	nb_bit;

	nb_bit = 1;
	while (num >= 2)
	{
		num /= 2;
		nb_bit++;
	}
	return (nb_bit);
}

static int	ft_extract_bit(int num, int num_bit, int nb_bit)
{
	int	bit;

	while (nb_bit >= num_bit)
	{
		nb_bit--;
		bit = num / ft_power(2, nb_bit);
		num -= bit * ft_power(2, nb_bit);
	}
	return (bit);
}

void	ft_sort_radix(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op)
{
	int	nb_bit;
	int	num_bit;
	int	bit;
	int	i;

	if (stack_a->size > 1)
	{
		nb_bit = ft_nb_bit(stack_a->max->norme);
		num_bit = 1;
		while (num_bit <= nb_bit)
		{
			i = stack_a->size;
			while (i > 0)
			{
				if (ft_stack_disorder(stack_a))
				{
					bit = ft_extract_bit(stack_a->top->norme, num_bit, nb_bit);
					if (bit)
						ft_stack_rotate(stack_a, lst_op);
					else
						ft_stack_push(stack_a, stack_b, lst_op);
					i--;
				}
				else
					i = 0;
			}
			while (stack_b->size)
				ft_stack_push(stack_b, stack_a, lst_op);
			num_bit++;
		}
	}
}
