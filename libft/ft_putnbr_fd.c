/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:20:35 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/20 16:13:40 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : Outputs the integer ’n’ to the given file descriptor.
*/
/*
Return : None
*/
static void	ft_write_mod(int n, int fd)
{
	char	c;

	if (n / 10 != 0)
		ft_write_mod(n / 10, fd);
	if (n < 0)
		c = 48 - n % 10;
	else
		c = 48 + n % 10;
	write(fd, &c, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		write(fd, "-", 1);
	ft_write_mod(n, fd);
}
