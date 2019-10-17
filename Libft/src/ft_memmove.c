/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:41:04 by winorth           #+#    #+#             */
/*   Updated: 2019/03/01 13:15:46 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*d;
	const char	*s;

	d = (char *)dst;
	s = (const char *)src;
	if (s < d)
	{
		i = (int)len;
		while ((int)--i >= 0)
			d[i] = s[i];
	}
	else
	{
		i = 0;
		while (len--)
		{
			d[i] = s[i];
			i++;
		}
	}
	return (d);
}
