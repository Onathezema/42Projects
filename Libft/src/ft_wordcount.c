/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 13:51:26 by winorth           #+#    #+#             */
/*   Updated: 2019/02/26 14:35:06 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_wordcount(const char *s, char c)
{
	size_t	count;
	int		num;

	count = 0;
	num = 0;
	while (*s)
	{
		if (!num && *s != c)
			count++;
		num = (*s == c) ? 0 : 1;
		s++;
	}
	return (count);
}
