/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:04:12 by winorth           #+#    #+#             */
/*   Updated: 2019/02/19 16:45:24 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[i] != '\0')
		j++;
	str = (char *)malloc(sizeof(*str) * (j));
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
