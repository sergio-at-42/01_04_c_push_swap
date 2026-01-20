/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:53:17 by Serge             #+#    #+#             */
/*   Updated: 2026/01/20 19:49:29 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_op_count(t_list_op *list_op, char op_type, char stack)
{
	t_op	*op;
	int		nb_op;

	nb_op = 0;
	op = list_op->first;
	while (op)
	{
		if (op->type == op_type && op->stack == stack)
			nb_op++;
		op = op->next;
	}
	return (nb_op);
}
