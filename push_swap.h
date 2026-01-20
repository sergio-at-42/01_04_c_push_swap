/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:50 by Serge             #+#    #+#             */
/*   Updated: 2026/01/20 19:46:08 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
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
}						t_stack;

// typedef struct s_clone
// {
// 	int					integer;
// 	struct s_element	*element;
// 	struct s_clone		*previous;
// 	struct s_clone		*next;
// }						t_clone;

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
int			ft_op_count(t_list_op *list_op, char op_type, char stack);
void		ft_op_del_lst(t_list_op *list_op);
void		ft_op_disp_lst(t_list_op *list_op);
void		ft_op_disp(t_op *op);
t_stack		*ft_stack_init(char name);
void		ft_stack_norme(t_stack *stack);
t_element	*ft_stack_add_element(t_stack *stack, int integer);
void		ft_stack_del(t_stack *stack);
void		ft_stack_push(t_stack *stack_out, t_stack *stack_in, t_list_op	*op);
// int			ft_stack_pop(t_stack *stack);
void		ft_stack_swap(t_stack *stack, t_list_op	*lst_op);
void		ft_stack_rotate(t_stack *stack, t_list_op *lst_op);
void		ft_stack_reverse_rotate(t_stack *stack, t_list_op *lst_op);
int			ft_stack_check(t_stack *stack);
float		ft_stack_disorder(t_stack *stack);
t_element	*ft_stack_min(t_stack *stack);
t_element	*ft_stack_max(t_stack *stack);
int			ft_stack_pos_min(t_stack *stack);
int			ft_stack_pos_max(t_stack *stack);
void		ft_stack_swap_pos(t_stack *stack, t_list_op *lst_op, int pos);
void		ft_sort_insertion(t_stack *stack_a, t_list_op	*lst_op);
void		ft_sort_selection(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op);
void		ft_sort_bubble(t_stack *stack_a, t_list_op *lst_op);
void		ft_sort_min_max(t_stack *stack_a, t_stack *stack_b, t_list_op	*lst_op);
void		ft_sort_radix(t_stack *stack_a, t_list_op	*lst_op);
void		ft_benchmark(t_stack *stack, t_list_op	*lst_op);

// int			ft_atoi(const char *nptr);
// char		*ft_itoa(int n);
// void		ft_putendl_fd(const char *s, int fd);
// void		ft_putnbr_fd(float n, int fd);
// void		ft_putstr_fd(const char *s, int fd);
// size_t		ft_strlcat(char *dst, const char *src, size_t size);
// size_t		ft_strlen(const char *s);

#endif
