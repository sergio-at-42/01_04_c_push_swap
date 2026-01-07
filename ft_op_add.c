/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_add.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 15:53:17 by Serge             #+#    #+#             */
/*   Updated: 2026/01/07 17:15:13 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op	*ft_op_add(t_list_op *list_op, char op_type, char stack)
{
	t_op	*op;

	op = (t_op *)malloc(sizeof(t_op));
	if (!op)
		return (NULL);
	op->type = op_type;
	op->stack = stack;
	op->next = NULL;
	if (list_op->first == NULL)
		list_op->first = op;
	else
		list_op->last->next = NULL;
	list_op->last = op;
	list_op->nb++;
	
	if (op_type == 'i')
		write(1,"rr",2);
	else
		write(1,&op_type,1);
	write(1,&stack,1);
	write(1,"\n",1);
	return (op);
}
