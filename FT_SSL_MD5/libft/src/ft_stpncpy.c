/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 17:49:51 by winorth           #+#    #+#             */
/*   Updated: 2019/10/04 17:49:53 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_stpncpy(char *s1, const char *s2, size_t n)
{
	char	*res;
	size_t	i;

	i = 0;
	while (i < n && s2[i])
	{
		s1[i] = s2[i];
		++i;
	}
	res = s1 + i;
	while (i < n)
		s1[i++] = '\0';
	return (res);
}
