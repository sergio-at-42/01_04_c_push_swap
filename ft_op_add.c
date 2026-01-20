/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:53:17 by Serge             #+#    #+#             */
/*   Updated: 2026/01/20 20:03:38 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	*ft_op_add(t_list_op *list_op, char op_type, char stack)
{
	t_op	*op;

	if (list_op->last && op_type != 'p')
		if (list_op->last->stack == 'a' || list_op->last->stack == 'b')
			if (list_op->last->type == op_type && list_op->last->stack != stack)
			{
				if (list_op->last->type == 's')
					list_op->last->stack = 's';
				else
					list_op->last->stack = 'r';
				return (list_op->last);
			}
	op = (t_op *)malloc(sizeof(t_op));
	if (!op)
		return (NULL);
	op->type = op_type;
	op->stack = stack;
	op->next = NULL;
	if (list_op->first == NULL)
		list_op->first = op;
	else
		list_op->last->next = op;
	list_op->last = op;
	list_op->nb++;
	return (op);
}
