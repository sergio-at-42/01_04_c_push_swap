/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 17:13:07 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/22 14:20:12 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : The strcmp() function compares the two strings s1 and s2. The 
locale is not taken into account (for a locale-aware comparison, see strcoll). 
The comparison is done using unsigned characters.
strcmp() returns an integer indicating the result of the comparison, as follows:
•  0, if the s1 and s2 are equal;
•  a negative value if s1 is less than s2;
•  a positive value if s1 is greater than s2.
The strncmp() function is similar, except it compares only the first (at most) 
n bytes of s1 and s2.
*/
/*
Return : The strcmp() and strncmp() functions return an integer less than, 
equal to, or greater than zero if s1 (or the first n bytes thereof) is found, 
respectively, to be less than, to match, or be greater than s2.
*/
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
