/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Serge <serge.beldjaoui@learner.42.tech>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 11:30:20 by sbeldjao          #+#    #+#             */
/*   Updated: 2026/01/20 16:14:58 by Serge            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Description : The strlcpy() and strlcat() functions copy and concatenate 
strings respectively. They are designed to be safer, more consistent, and less 
error prone replacements for strncpy(3) and strncat(3). Unlike those functions, 
strlcpy() and strlcat() take the full size of the buffer (not just the length) 
and guarantee to NUL-terminate the result (as long as size is larger than 0 or, 
in the case of strlcat(), as long as there is at least one byte free in dst). 
Note that a byte for the NUL should be included in size. 
Also note that  strlcpy()  and  strlcat()  only  operate  on  true  “C” strings.
 This means that for strlcpy() src must be NUL-terminated and for strlcat() both
 src and dst must be NUL-terminated.
The strlcpy() function copies up to size - 1 characters from the NUL-terminated 
string src to dst, NUL-terminating the result.
The strlcat() function appends the NUL-terminated string src to the end of dst. 
It will append at most size - strlen(dst) - 1 bytes, NUL-terminating 
the result.
*/
/*
Return : The strlcpy() and strlcat() functions return the total length of 
the string they tried to create. 
For strlcpy() that means the length of src. 
For strlcat() that means the initial length of dst plus the length of src. 
While this may seem somewhat confusing, it was done to make truncation 
detection simple.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*p_src;
	size_t	len_src;
	size_t	len_dst;
	size_t	i;

	p_src = (char *)src;
	len_src = ft_strlen(p_src);
	len_dst = ft_strlen(dst);
	if (size == 0)
		return (len_src);
	if (size < len_dst)
		return (size + len_src);
	i = len_dst;
	size--;
	while (i < size && p_src[i - len_dst] != '\0')
	{
		dst[i] = p_src[i - len_dst];
		i++;
	}
	dst[i] = '\0';
	return (len_dst + len_src);
}
