/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:50 by Serge             #+#    #+#             */
/*   Updated: 2026/01/05 20:07:42 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct s_element
{
	int					integer;
	struct s_element	*previous;
	struct s_element	*next;
}						t_element;

typedef struct s_stack
{
	struct s_element	*top;
	struct s_element	*last;
	int					size;
}						t_stack;

int			ft_return_error(void);
t_stack		*ft_stack_init(void);
t_element	*ft_stack_push(t_stack *stack, int integer);
int			ft_stack_pop(t_stack *stack);
void		ft_stack_swap(t_stack *stack);
void		ft_stack_rotate(t_stack *stack);
void		ft_stack_reverse_rotate(t_stack *stack);
int			ft_atoi(const char *nptr);
void		ft_insertion_sort(t_stack *stack_a, t_stack *stack_b);

#endif
