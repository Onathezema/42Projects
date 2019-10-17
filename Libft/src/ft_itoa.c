/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:31:00 by winorth           #+#    #+#             */
/*   Updated: 2019/03/16 12:50:43 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		nlen(intmax_t n)
{
	int	i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(intmax_t n)
{
	char	*str;
	long	j;
	int		i;
	int		c;

	j = n;
	i = (n < 0) ? nlen(n) + 1 : nlen(n);
	if ((str = ft_strnew(i)))
	{
		while (i--)
		{
			c = j % 10;
			str[i] = c < 0 ? -c + '0' : c + '0';
			j /= 10;
		}
		if (n < 0)
			str[0] = '-';
		return (str);
	}
	return (NULL);
}
