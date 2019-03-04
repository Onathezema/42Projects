/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:30:50 by winorth           #+#    #+#             */
/*   Updated: 2019/02/23 15:30:57 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int position;
	unsigned int i;

	if (!*needle)
		return ((char *)haystack);
	position = 0;
	while (haystack[position] != '\0' && (size_t)position < len)
	{
		if (haystack[position] == needle[0])
		{
			i = 1;
			while (needle[i] != '\0' && haystack[position + 1] == needle[i] &&
			(size_t)(position + i) < len)
				++i;
			if (needle[i] == '\0')
				return ((char *)&haystack[position]);
		}
		++position;
	}
	return (0);
}
