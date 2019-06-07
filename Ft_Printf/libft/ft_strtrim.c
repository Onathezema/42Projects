/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:46:59 by winorth           #+#    #+#             */
/*   Updated: 2019/02/25 19:34:14 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	strt;
	size_t	fin;

	if (!s)
		return (NULL);
	strt = 0;
	while (ft_isstrwhitespaces(s[strt]))
		strt++;
	fin = ft_strlen(s);
	while (ft_isstrwhitespaces(s[fin - 1]))
		fin--;
	if (fin < strt)
		fin = strt;
	return (ft_strsub(s, strt, fin - strt));
}
