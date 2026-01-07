/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:50 by Serge             #+#    #+#             */
/*   Updated: 2026/01/07 17:28:58 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_element
{
	int					integer;
	struct s_element	*previous;
	struct s_element	*next;
}						t_element;

typedef struct s_stack
{
	char				name;
	struct s_element	*top;
	struct s_element	*last;
	int					size;
}						t_stack;

// typedef	enum e_op_type {
// 	s, p, r, rr
// }	t_op_type;

typedef struct s_op
{
	char			type;
	char			stack;
	struct s_op		*next;
}					t_op;

typedef struct s_list_op
{
	struct s_op	*first;
	struct s_op	*last;
	int			nb;
}				t_list_op;

int			ft_return_error(void);
t_list_op	*ft_op_init();
t_op		*ft_op_add(t_list_op *list_op, char op_type, char stack);
t_stack		*ft_stack_init(char name);
t_element	*ft_stack_add_element(t_stack *stack, int integer);
int			ft_stack_del_element(t_stack *stack);
void		ft_stack_push(t_stack *stack_out, t_stack *stack_in, t_list_op	*op);
// int			ft_stack_pop(t_stack *stack);
void		ft_stack_swap(t_stack *stack, t_list_op	*lst_op);
void		ft_stack_rotate(t_stack *stack, t_list_op *lst_op);
void		ft_stack_reverse_rotate(t_stack *stack, t_list_op *lst_op);
int			ft_atoi(const char *nptr);
void		ft_insertion_sort(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op);
int			ft_stack_check(t_stack *stack);

#endif
