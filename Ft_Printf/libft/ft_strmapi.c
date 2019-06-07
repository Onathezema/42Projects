/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:11:43 by winorth           #+#    #+#             */
/*   Updated: 2019/03/01 12:43:22 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*end;
	size_t	i;

	if (!s || !f)
		return (NULL);
	end = ft_strnew(ft_strlen(s));
	if (!end)
		return (NULL);
	ft_strcpy(end, s);
	i = -1;
	while (*(end + ++i))
		*(end + i) = f(i, *(end + i));
	return (end);
}
