/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 13:57:51 by winorth           #+#    #+#             */
/*   Updated: 2019/02/28 18:41:21 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *end;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	end = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!end)
		return (NULL);
	ft_strcpy(end, s1);
	ft_strcat(end, s2);
	return (end);
}
