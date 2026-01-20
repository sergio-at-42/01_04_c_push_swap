/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_del_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:53:17 by Serge             #+#    #+#             */
/*   Updated: 2026/01/20 19:40:19 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_del_lst(t_list_op *list_op)
{
	t_op	*op;

	while (list_op->first)
	{
		op = list_op->first;
		list_op->first = op->next;
		free(op);
	}
	free(list_op);
}
