/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ps_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 17:52:13 by Serge             #+#    #+#             */
/*   Updated: 2026/02/02 20:22:43 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_check_option(char *arg, t_list_op *lst_op)
{
	if (ft_strcmp(arg, "--bench") == 0)
		lst_op->benchmark = 1;
	else if (ft_strcmp(arg, "--simple") == 0)
		lst_op->strategy = 's';
	else if (ft_strcmp(arg, "--medium") == 0)
		lst_op->strategy = 'm';
	else if (ft_strcmp(arg, "--complex") == 0)
		lst_op->strategy = 'c';
	else if (ft_strcmp(arg, "--adaptive") == 0)
		lst_op->strategy = 'a';
	else
		return (0);
	return (1);
}

static int	ft_check_num(char *arg)
{
	int	error;
	int	i;

	error = 0;
	i = 0;
	while (arg[i] != '\0')
	{
		if (!(arg[i] >= 9 && arg[i] <= 13) && arg[i] != 32
			&& arg[i] != '-' && arg[i] != '+'
			&& !(arg[i] >= 48 && arg[i] <= 57))
			error = 1;
		i++;
	}
	return (error);
}

static int	ft_check_double(int arg_int, t_stack *stack)
{
	t_element	*element;
	int			i;

	element = stack->top;
	i = 1;
	while (i <= stack->size)
	{
		if (element->integer == arg_int)
			return (1);
		element = element->next;
		i++;
	}
	return (0);
}

static int	ft_check_limit(long arg_long)
{
	if (arg_long < -2147483648 || arg_long > 2147483647)
		return (1);
	return (0);
}

int	ft_ps_parser(int argc, char **argv, t_stack *stack, t_list_op *lst_op)
{
	int	error;
	int	i;

	error = 0;
	if (argc > 1)
	{
		i = 1;
		while (i < argc && !error)
		{
			if (!ft_check_option(argv[i], lst_op))
			{
				error += ft_check_num(argv[i]);
				error += ft_check_limit(ft_atol(argv[i]));
				error += ft_check_double((int)ft_atol(argv[i]), stack);
				if (!error)
					ft_stack_add_element(stack, (int)ft_atol(argv[i]));
			}
			i++;
		}
		ft_stack_norme(stack);
		stack->disorder = ft_stack_disorder(stack);
	}
	return (error);
}
