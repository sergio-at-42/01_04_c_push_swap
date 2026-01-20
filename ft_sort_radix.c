/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_radix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:46:12 by Serge             #+#    #+#             */
/*   Updated: 2026/01/19 17:14:56 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	display_stack(t_stack *stack)
{
	int			i;
	t_element	*element;

	printf("vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvstack %c   <===>   stack->min\n", stack->name, stack->min);
	i = 0;
	element = stack->top;
	while (i < stack->size)
	{
		printf("   %d", element->norme);
		i++;
		element = element->next;
	}
	printf("\n");
	printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
}

static int	ft_nb_digit(int num)
{
	int	nb_digit;

	nb_digit = 1;
	while (num >= 10)
	{
		num /= 10;
		nb_digit++;
	}
	return (nb_digit);
}

static int	ft_extract_digit(int num, int num_digit)
{
	int	digit;

	while (num_digit > 1)
	{
		num /= 10;
		num_digit--;
	}
	digit = num % 10;
	return (digit);
}

void	ft_sort_radix(t_stack *stack, t_list_op	*lst_op)
{
	t_element	*first;
	t_element	*element_next;
	int	nb_digit;
	int	num_digit;
	int	digit;
	int	nb_rotate;
	int	i;

	if (stack->size > 1)
	{
		first = stack->top;
		nb_digit = ft_nb_digit(stack->max->norme);
		num_digit = 1;
		while (num_digit <= nb_digit)
		{
			i = 1;
			while (i <= stack->size)
			{
				element_next = stack->top->next;
				digit = ft_extract_digit(stack->top->norme, num_digit);
				nb_rotate = 0;
				while (digit < ft_extract_digit(stack->top->previous->norme, num_digit) && stack->top != first)
				{
					ft_stack_reverse_rotate(stack, lst_op);
					ft_stack_swap(stack, lst_op);
					if (stack->top->next == first)
						first = stack->top;
					nb_rotate++;
				}

				// while (digit > ft_extract_digit(stack->top->next->norme, num_digit) && stack->top->next != first)
				// {
				// 	ft_stack_swap(stack, lst_op);
				// 	if (stack->top->next == first)
				// 		first = stack->top;
				// 	ft_stack_rotate(stack, lst_op);
				// 	nb_rotate++;
				// 	// digit = ft_extract_digit(stack->top->norme, num_digit);
				// 	// digit_next = ft_extract_digit(stack->top->next->norme, num_digit);
				// }

				if (nb_rotate)
				{				
					nb_rotate = nb_rotate / (stack->size / 2);
					while (stack->top != element_next)
					{
						if (nb_rotate)
							ft_stack_reverse_rotate(stack, lst_op);
						else
							ft_stack_rotate(stack, lst_op);
					}
				}
				else
					ft_stack_rotate(stack, lst_op);
				i++;
			}
			num_digit++;
		}
	}
}
