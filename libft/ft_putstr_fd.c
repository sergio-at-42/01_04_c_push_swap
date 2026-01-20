/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 11:15:03 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/20 15:49:36 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : Outputs the string ’s’ to the given file descriptor.
*/
/*
Return : None
*/
void	ft_putstr_fd(const char *s, int fd)
{
	if (s)
		write(fd, s, ft_strlen(s));
}
