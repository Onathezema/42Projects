/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:38:06 by winorth           #+#    #+#             */
/*   Updated: 2019/02/22 16:09:16 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*des;
	const char	*source;

	des = dst;
	source = src;
	while (n)
	{
		*des = *source;
		des++;
		source++;
		n--;
	}
	return (dst);
}
