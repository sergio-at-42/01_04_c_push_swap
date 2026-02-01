/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 16:41:16 by Serge             #+#    #+#             */
/*   Updated: 2026/01/30 17:45:33 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list_op	*ft_op_init(void)
{
	t_list_op	*lst_op;

	lst_op = (t_list_op *)malloc(sizeof(t_list_op));
	if (!lst_op)
		return (NULL);
	lst_op->first = NULL;
	lst_op->last = NULL;
	lst_op->nb = 0;
	lst_op->benchmark = 0;
	lst_op->strategy = 'a';
	return (lst_op);
}
