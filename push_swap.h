/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:50 by Serge             #+#    #+#             */
/*   Updated: 2026/02/01 15:52:33 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct s_element
{
	int					integer;
	int					norme;
	struct s_element	*previous;
	struct s_element	*next;
}						t_element;

typedef struct s_stack
{
	char				name;
	struct s_element	*top;
	struct s_element	*last;
	struct s_element	*min;
	struct s_element	*max;
	int					size;
	float				disorder;
}						t_stack;

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
	int			benchmark;
	char		strategy;
}				t_list_op;

int			ft_ps_error(int error);
int			ft_ps_parser(int argc, char **argv, t_stack *stack,
				t_list_op *lst_op);
void		ft_ps_benchmark(t_stack *stack, t_list_op *lst_op);
t_list_op	*ft_op_init(void);
t_op		*ft_op_add(t_list_op *list_op, char op_type, char stack);
int			ft_op_count(t_list_op *list_op, char op_type, char stack);
void		ft_op_del_lst(t_list_op *list_op);
void		ft_op_disp_lst(t_list_op *list_op);
void		ft_op_disp(t_op *op);
t_stack		*ft_stack_init(char name);
void		ft_stack_norme(t_stack *stack);
t_element	*ft_stack_add_element(t_stack *stack, int integer);
void		ft_stack_del(t_stack *stack);
void		ft_stack_push(t_stack *stack_out, t_stack *stack_in,
				t_list_op *op);
void		ft_stack_swap(t_stack *stack, t_list_op	*lst_op);
void		ft_stack_rotate(t_stack *stack, t_list_op *lst_op);
void		ft_stack_reverse_rotate(t_stack *stack, t_list_op *lst_op);
float		ft_stack_disorder(t_stack *stack);
t_element	*ft_stack_min(t_stack *stack);
t_element	*ft_stack_max(t_stack *stack);
int			ft_stack_pos_min(t_stack *stack);
int			ft_stack_pos_max(t_stack *stack);
void		ft_stack_swap_pos(t_stack *stack, t_list_op *lst_op, int pos);
void		ft_sort_small(t_stack *stack_a, t_list_op *lst_op);
void		ft_sort_selection(t_stack *stack_a, t_stack *stack_b,
				t_list_op *lst_op);
void		ft_sort_bucket(t_stack *stack_a, t_stack *stack_b,
				t_list_op *lst_op);
void		ft_sort_radix(t_stack *stack_a, t_stack *stack_b,
				t_list_op *lst_op);

#endif
