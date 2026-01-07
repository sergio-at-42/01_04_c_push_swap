/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/07 18:56:19 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void	display_stack(t_stack *stack)
// {
// 	t_element	*element;

// 	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv\n");
// 	element = stack->top;
// 	while (element)
// 	{
// 		printf("%d\n", element->integer);
// 		element = element->next;
// 	}
// 	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
// }

void	ft_insertion_sort(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op)
{
	if (stack_a->size > 1)
	{
		if (stack_a->top->next->integer < stack_a->top->integer)
		{
			ft_stack_swap(stack_a, lst_op);
		}
		if (stack_a->size > 2)
		{
			ft_stack_push(stack_a, stack_b, lst_op);
			ft_stack_push(stack_a, stack_b, lst_op);
			while (stack_a->size)
			{
				if (stack_a->top->integer < stack_b->top->integer)
				{
					while (stack_a->top->integer < stack_b->top->integer)
					{
						ft_stack_rotate(stack_b, lst_op);
						if (stack_b->top->integer > stack_b->last->integer && 
							(stack_a->top->integer < stack_b->last->integer || stack_a->top->integer > stack_b->top->integer))
								break;
					}
				}
				else
				{
					while (stack_a->top->integer > stack_b->last->integer)
					{
						ft_stack_reverse_rotate(stack_b, lst_op);
						if (stack_b->top->integer > stack_b->last->integer && 
							(stack_a->top->integer < stack_b->last->integer || stack_a->top->integer > stack_b->top->integer))
								break;
					}
				}
				ft_stack_push(stack_a, stack_b, lst_op);
			}
			while (stack_b->last->integer >= stack_b->top->integer)
				ft_stack_reverse_rotate(stack_b, lst_op);
			while (stack_b->size)
				ft_stack_push(stack_b, stack_a, lst_op);
		}
	}
}
