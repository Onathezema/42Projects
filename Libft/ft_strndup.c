/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:02:40 by winorth           #+#    #+#             */
/*   Updated: 2019/03/05 14:43:13 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_strndup(const char *s, size_t n)
{
	char	*des;
	char	*tem;

	if (!(des = (char *)malloc(sizeof(char) * (n + 1))))
		return (0);
	tem = des;
	while (n)
	{
		*tem++ = *s++;
		n--;
	}
	*tem = '\0';
	return (*des);
}
