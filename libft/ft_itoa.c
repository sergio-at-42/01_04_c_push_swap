/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 10:51:37 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/20 16:14:33 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : Allocates (with malloc) and returns a string representing 
the integer received as an argument. Negative numbers must be handled.
*/
/*
Return : The string representing the integer. NULL if the allocation fails.
*/
static long	ft_nb_digit(long n)
{
	int	nb_c;

	if (!n)
		return (1);
	nb_c = 0;
	while (n > 0)
	{
		n /= 10;
		nb_c++;
	}
	return (nb_c);
}

char	*ft_itoa(int n)
{
	int			nb_c;
	char		*c;
	int			sign;
	long int	long_n;

	long_n = (long int)n;
	sign = 0;
	if (long_n < 0)
	{
		sign = 1;
		long_n = -long_n;
	}
	nb_c = ft_nb_digit(long_n) + sign;
	c = (char *)malloc((nb_c + 1) * sizeof(char));
	if (sign)
		c[0] = '-';
	c[nb_c] = '\0';
	while (nb_c > sign)
	{
		nb_c--;
		c[nb_c] = (long_n % 10) + 48;
		long_n /= 10;
	}
	return (c);
}
