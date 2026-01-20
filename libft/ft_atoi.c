/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 16:15:07 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/20 16:14:07 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : checks for white-space characters. In the "C" and "POSIX" 
locales, these are : 
- horizontal tab ('\t')(9)
- newline ('\n')(10)
- vertical tab ('\v')(11)
- form-feed ('\f')(12)
- carriage return ('\r')(13)
- space (' ')(32)
*/
/*
Return : The values returned are nonzero (1) if the character c falls into 
the tested class, and zero (0) if not.
*/
static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/*
Description : The atoi() function converts the initial portion of the string 
pointed to by nptr to int. The behavior is the same as strtol(nptr, NULL, 10);
checks for white-space characters. In the "C" and "POSIX" locales, these are: 
space, 
form-feed ('\f'), 
newline ('\n'), 
carriage return ('\r'), 
horizontal tab ('\t'), 
and vertical tab ('\v').
*/
/*
Return : The converted value or 0 on error.
*/
int	ft_atoi(const char *nptr)
{
	int		integer;
	int		sign;
	int		i;

	integer = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57 && nptr[i] != '\0')
	{
		integer = integer * 10 + nptr[i] - 48;
		i++;
	}
	return (integer * sign);
}
