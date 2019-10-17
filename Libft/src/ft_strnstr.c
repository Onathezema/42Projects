/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:30:50 by winorth           #+#    #+#             */
/*   Updated: 2019/03/11 19:21:07 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int position;
	unsigned int i;

	if (*needle == '\0')
		return ((char *)haystack);
	position = 0;
	while (haystack[position] != '\0' && (size_t)position < len)
	{
		i = 0;
		while (needle[i] && haystack[position + i] == needle[i] &&
		position + i < len)
			i++;
		if (needle[i] == '\0')
			return ((char *)haystack + position);
		position++;
	}
	return (0);
}
