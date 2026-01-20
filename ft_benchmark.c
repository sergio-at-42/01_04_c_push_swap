/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_benchmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:55:44 by Serge             #+#    #+#             */
/*   Updated: 2026/01/20 20:59:09 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_disp_bench_discoder(t_stack *stack)
{
	ft_putstr_fd("[bench] disorder:	", 2);
	ft_putnbr_fd((int)(ft_stack_disorder(stack) * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(((int)(ft_stack_disorder(stack) * 10000)) % 100, 2);
	ft_putendl_fd("%", 2);
}

static	void	ft_disp_bench_strategy()
{
	ft_putstr_fd("[bench] strategy:	", 2);
	ft_putstr_fd("Adaptive / O(n n)", 2);
	ft_putendl_fd("", 2);
}

static	void	ft_disp_bench_total_ops(t_list_op *lst_op)
{
	ft_putstr_fd("[bench] total_ops:	", 2);
	ft_putnbr_fd(lst_op->nb, 2);
	ft_putendl_fd("", 2);
}

static	void	ft_disp_bench_ops(t_list_op *lst_op)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("sa:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 's', 'a'), 2);
	ft_putstr_fd("	sb:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 's', 'b'), 2);
	ft_putstr_fd("	ss:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 's', 's'), 2);
	ft_putstr_fd("	pa:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'p', 'a'), 2);
	ft_putstr_fd("	pb:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'p', 'b'), 2);
	ft_putendl_fd("", 2);
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("ra:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'r', 'a'), 2);
	ft_putstr_fd("	rb:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'r', 'b'), 2);
	ft_putstr_fd("	rr:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'r', 'r'), 2);
	ft_putstr_fd("	rra:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'i', 'a'), 2);
	ft_putstr_fd("	rrb:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'i', 'b'), 2);
	ft_putstr_fd("	rrr:	", 2);
	ft_putnbr_fd(ft_op_count(lst_op, 'i', 'r'), 2);
	ft_putendl_fd("", 2);
}

void	ft_benchmark(t_stack *stack, t_list_op *lst_op)
{
	ft_disp_bench_discoder(stack);
	ft_disp_bench_strategy();
	ft_disp_bench_total_ops(lst_op);
	ft_disp_bench_ops(lst_op);
}
