/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_disp_lst.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfuente <stfuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:52:02 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 14:20:15 by stfuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_disp_lst(t_list_op *list_op)
{
	t_op	*op;

	op = list_op->first;
	while (op)
	{
		ft_op_disp(op);
		op = op->next;
	}
}
