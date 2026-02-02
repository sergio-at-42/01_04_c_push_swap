/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_disp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stfuente <stfuente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:52:02 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 14:20:12 by stfuente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_op_disp(t_op *op)
{
	if (op->type == 'i')
		ft_putstr_fd("rr", 1);
	else
		ft_putchar_fd(op->type, 1);
	ft_putchar_fd(op->stack, 1);
	ft_putendl_fd("", 1);
}
