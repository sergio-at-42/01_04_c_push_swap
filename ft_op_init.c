/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:41:16 by Serge             #+#    #+#             */
/*   Updated: 2026/01/07 16:41:20 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_op	*ft_op_init()
{
	t_list_op	*lst_op;

	lst_op = (t_list_op *)malloc(sizeof(t_list_op));
	if (!lst_op)
		return (NULL);
	lst_op->first = NULL;
	lst_op->last = NULL;
	lst_op->nb = 0;
	return (lst_op);
}
