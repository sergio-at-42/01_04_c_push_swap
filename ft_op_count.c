/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_count.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfuente <stfuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:53:17 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 14:20:19 by stfuente         ###   ########.fr       */
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
