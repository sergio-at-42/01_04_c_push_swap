/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_insertion.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/09 18:14:04 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_stack(t_stack *stack)
{
	t_element	*element;

	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
	element = stack->top;
	while (element)
	{
		printf("   %d", element->integer);
		element = element->next;
	}
	printf("\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}

void	ft_sort_insertion(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op)
{
	int			pos;
	// int			j;
	// t_element	*element;


	while (stack_a->size > 1)
	{
		if (stack_b->size > 1)
		{
			if (stack_a->top->integer > stack_b->max->integer)
				ft_stack_swap_pos(stack_b, lst_op, ft_stack_pos_max(stack_b));
			else if (stack_a->top->integer < stack_b->min->integer)
			{
				if (stack_b->min != stack_b->last)
				{
					ft_stack_swap_pos(stack_b, lst_op, ft_stack_pos_min(stack_b));
					ft_stack_rotate(stack_b, lst_op);
				}
			}
			else if (!(stack_a->top->integer > stack_b->top->integer && stack_a->top->integer < stack_b->last->integer))
			{
				pos = 1;
				while (pos < stack_b->size)
				{
					if (stack_a->top->integer < (stack_b->top + pos - 1)->integer && stack_a->top->integer > (stack_b->top + pos)->integer)
						break;
					else
						pos++;
				}
				ft_stack_swap_pos(stack_b, lst_op, pos);
			}
		}
		ft_stack_push(stack_a, stack_b, lst_op);
		if (stack_b->size == 2 && stack_b->top->integer < stack_b->top->next->integer)
			ft_stack_rotate(stack_b, lst_op);
display_stack(stack_b);
	}
	while (stack_b->size)
		ft_stack_push(stack_b, stack_a, lst_op);











	// i = 2;
	// while (i <= stack_a->size)
	// {
	// 	j = 1;
	// 	while (stack_a->top->integer < stack_a->last->integer)
	// 	{
	// 		ft_stack_reverse_rotate(stack_a, lst_op);
	// 		ft_stack_swap(stack_a, lst_op);
	// 		j++;
	// 	}
	// 	j = 1;
	// 	while (j > 1)
	// 	{
	// 		ft_stack_rotate(stack_a, lst_op);
	// 		j--;
	// 	}
	// 	i++;
	// }



	// while (stack_a->top->integer > stack_a->last->integer)
	// {
	// 	ft_stack_rotate(stack_a, lst_op);
	// }
	
	// while (stack_a->top->integer < stack_a->last->integer && j > 1)
	// {
	// 	ft_stack_reverse_rotate(stack_a, lst_op);
	// 	ft_stack_swap(stack_a, lst_op);
	// }



	// i = 1;
	// j = 1;
	// while (i <= stack_a->size)
	// {
	
	// 	while (stack_a->top->next->integer < stack_a->top->integer && j > 1)
	// 	{
	// 		ft_stack_swap(stack_a, lst_op);
	// 		if (j > 2)
	// 			ft_stack_reverse_rotate(stack_a, lst_op);
	// 		j--;
	// 	}
	// 	while (j <= i)
	// 	{
	// 		ft_stack_rotate(stack_a, lst_op);
	// 		j++;
	// 	}
		
	// 	i++;
	// }



	// if (stack_a->size > 1)
	// {
	
		






	// 	if (stack_a->top->next->integer < stack_a->top->integer)
	// 	{
	// 		ft_stack_swap(stack_a, lst_op);
	// 	}
	// 	if (stack_a->size > 2)
	// 	{
	// 		ft_stack_push(stack_a, stack_b, lst_op);
	// 		ft_stack_push(stack_a, stack_b, lst_op);
	// 		while (stack_a->size)
	// 		{
	// 			// element = stack_b->top;
	// 			i = 0;
	// 			if (stack_a->top->integer < stack_b->min->integer)
	// 				while ((stack_b->top + i) != stack_b->min)
	// 					i++;
	// 			else if (stack_a->top->integer > stack_b->max->integer)
	// 				while ((stack_b->top + i) != stack_b->max)
	// 					i++;
	// 			else if (stack_a->top->integer < stack_b->top->integer || stack_a->top->integer > stack_b->last->integer)
	// 			{
	// 				// i = 1;
	// 				while (!(stack_a->top->integer > (stack_b->top+i-1)->integer || stack_a->top->integer <= (stack_b->top+i)->integer))
	// 					i++;
	// 			}
	// 			// if (stack_b->size / 2 > i)
	// 				while (i--)
	// 					ft_stack_rotate(stack_b, lst_op);
	// 			// else
	// 			// {
	// 			// 	i = stack_b->size - i;
	// 			// 	while (i--)
	// 			// 		ft_stack_reverse_rotate(stack_b, lst_op);
	// 			// }



	// 			// if (stack_a->top->integer < stack_b->top->integer)
	// 			// {
	// 			// 	while (stack_a->top->integer < stack_b->top->integer)
	// 			// 	{
	// 			// 		ft_stack_rotate(stack_b, lst_op);
	// 			// 		if (stack_b->top->integer > stack_b->last->integer && 
	// 			// 			(stack_a->top->integer < stack_b->last->integer || stack_a->top->integer > stack_b->top->integer))
	// 			// 				break;
	// 			// 	}
	// 			// }
	// 			// else
	// 			// {
	// 			// 	while (stack_a->top->integer > stack_b->last->integer)
	// 			// 	{
	// 			// 		ft_stack_reverse_rotate(stack_b, lst_op);
	// 			// 		if (stack_b->top->integer > stack_b->last->integer && 
	// 			// 			(stack_a->top->integer < stack_b->last->integer || stack_a->top->integer > stack_b->top->integer))
	// 			// 				break;
	// 			// 	}
	// 			// }
	// 			ft_stack_push(stack_a, stack_b, lst_op);
	// 		}
	// 		while (stack_b->last->integer >= stack_b->top->integer)
	// 			ft_stack_reverse_rotate(stack_b, lst_op);
	// 		while (stack_b->size)
	// 			ft_stack_push(stack_b, stack_a, lst_op);
	// 	}
	// }
}
