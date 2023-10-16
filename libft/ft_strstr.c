/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmadzaaza <ahmadzaaza@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 19:59:46 by ahmadzaaza        #+#    #+#             */
/*   Updated: 2023/10/15 20:10:16 by ahmadzaaza       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
@description:
The	strstr(void) function locates the first occurrence of the null-terminated
		string needle in the null-terminated string haystack.

@returnvalues:
If needle is an empty string, haystack is returned; if needle occurs
nowhere in haystack, NULL is returned; otherwise a pointer to the first
character of the first occurrence of needle is returned.
*/
char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;
	int needle_len;

	needle_len = ft_strlen(needle);
	if (!needle_len)
		return ((char *)haystack);
	i = 0;

	while (haystack[i])
	{
		j = 0;
		while (needle[j] && needle[j] == haystack[i + j])
			j++;
		if (needle_len == j)
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}