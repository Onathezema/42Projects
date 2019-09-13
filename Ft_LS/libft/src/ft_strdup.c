/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:04:12 by winorth           #+#    #+#             */
/*   Updated: 2019/03/12 15:59:56 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	str = (char *)malloc(sizeof(char) * j + 1);
	if (!str)
		return (NULL);
	while (i < j)
	{
		str[i] = s1[i];
		i++;
	}
	str[j] = '\0';
	return (str);
}
