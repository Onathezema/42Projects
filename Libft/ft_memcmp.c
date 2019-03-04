/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:37:02 by winorth           #+#    #+#             */
/*   Updated: 2019/02/27 13:13:53 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s3;
	unsigned char	*s4;
	size_t			i;

	i = 0;
	*s3 = (unsigned char *)s1;
	*s4 = (unsigned char *)s2;
	while (i < n && *s3 == *s4)
	{
		i++;
		s3++;
		s4++;
	}
	if (i == n)
		return (0);
	return (*s3 - *s4);
}
