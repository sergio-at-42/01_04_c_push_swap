/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:06:50 by Serge             #+#    #+#             */
/*   Updated: 2026/01/03 17:42:40 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

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
	unsigned int		size;
}						t_stack;

#endif
