/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:11:49 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/20 19:34:58 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : Outputs the character ’c’ to the given file descriptor.
*/
/*
Return : None
*/
void	ft_putchar_fd(const char c, int fd)
{
	write(fd, &c, 1);
}
