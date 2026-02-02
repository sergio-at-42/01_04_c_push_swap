/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_benchmark.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 13:55:44 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 18:40:01 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_disp_bench_discoder(t_stack *stack)
{
	ft_putstr_fd("[bench] disorder:	", 2);
	ft_putnbr_fd((int)(stack->disorder * 100), 2);
	ft_putstr_fd(".", 2);
	ft_putnbr_fd(((int)(stack->disorder * 1000)) % 10, 2);
	ft_putnbr_fd(((int)(stack->disorder * 10000)) % 10, 2);
	ft_putendl_fd("%", 2);
}

static	void	ft_disp_bench_strategy(t_stack *stack, t_list_op *lst_op)
{
	ft_putstr_fd("[bench] strategy:	", 2);
	if (lst_op->strategy == 't')
		ft_putstr_fd("Small Sort (size <= 5)", 2);
	else if (lst_op->strategy == 's')
		ft_putstr_fd("Simple / O(n²)", 2);
	else if (lst_op->strategy == 'm')
		ft_putstr_fd("Medium / O(n√n)", 2);
	else if (lst_op->strategy == 'c')
		ft_putstr_fd("Complex / O(n log n)", 2);
	else if (lst_op->strategy == 'a')
	{
		ft_putstr_fd("Adaptive / ", 2);
		if (stack->disorder < 0.2)
			ft_putstr_fd("O(n²)", 2);
		else if (stack->disorder >= 0.2 && stack->disorder < 0.5)
			ft_putstr_fd("O(n√n)", 2);
		else
			ft_putstr_fd("O(n log n)", 2);
	}
	ft_putendl_fd("", 2);
}

static	void	ft_disp_bench_ops1(t_list_op *lst_op)
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
}

static	void	ft_disp_bench_ops2(t_list_op *lst_op)
{
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

void	ft_ps_benchmark(t_stack *stack, t_list_op *lst_op)
{
	ft_disp_bench_discoder(stack);
	ft_disp_bench_strategy(stack, lst_op);
	ft_putstr_fd("[bench] total_ops:	", 2);
	ft_putnbr_fd(lst_op->nb, 2);
	ft_putendl_fd("", 2);
	ft_disp_bench_ops1(lst_op);
	ft_disp_bench_ops2(lst_op);
}
