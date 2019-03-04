/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 14:36:15 by winorth           #+#    #+#             */
/*   Updated: 2019/02/26 18:25:38 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**i;
	size_t	ins;
	size_t	group;
	size_t	j;
	size_t	start;

	if (!s)
		return (NULL);
	if (!(i = (char **)ft_memalloc((ft_wordcount(s, c) + 1) * sizeof(char *))))
		return (NULL);
	group = 0;
	ins = 0;
	j = -1;
	start = 0;
	while (s[++j])
	{
		if (ins && s[j] == c)
			i[group++] = ft_strsub(s, start, j - start);
		if (!ins && s[j] != c)
			start = j;
		ins = (s[j] == c) ? 0 : 1;
	}
	if (ins)
		i[ins] = ft_strsub(s, start, j - start);
	return (i);
}
