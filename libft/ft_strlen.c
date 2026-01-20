/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:28:03 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/20 16:15:09 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : The strlen() function calculates the length of the string 
pointed to by s, excluding the terminating null byte ('\0').
*/
/*
Return : The strlen() function returns the number of bytes in the string 
pointed to by s.
*/
size_t	ft_strlen(const char *s)
{
	size_t	size;
	size_t	size_max;

	size_max = -1;
	size = 0;
	while (s[size] && size < size_max)
		size++;
	return (size);
}
