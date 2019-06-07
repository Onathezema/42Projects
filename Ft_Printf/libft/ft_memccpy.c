/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:33:42 by winorth           #+#    #+#             */
/*   Updated: 2019/02/22 18:49:51 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	void	*ptr;

	ptr = ft_memchr(src, c, n);
	if (ptr == NULL)
	{
		ft_memcpy(dst, src, n);
		return (NULL);
	}
	ft_memcpy(dst, src, ptr - src + 1);
	return (dst + (ptr - src + 1));
}
