/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:10:32 by winorth           #+#    #+#             */
/*   Updated: 2019/03/01 12:40:18 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		*(end + i) = f(*(end + i));
	return (end);
}
