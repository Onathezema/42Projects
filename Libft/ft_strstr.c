/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:37:27 by winorth           #+#    #+#             */
/*   Updated: 2019/03/06 13:24:36 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned int position;
	unsigned int i;

	if (!*needle && !*haystack)
		return ((char *)haystack);
	position = 0;
	while (haystack[position] != '\0')
	{
		i = 0;
		while (needle[i] != '\0' && haystack[position + i] == needle[i])
			++i;
		if (needle[i] == '\0')
			return ((char *)haystack + position);
		++position;
	}
	return (0);
}
