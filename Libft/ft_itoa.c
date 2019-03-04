/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:31:00 by winorth           #+#    #+#             */
/*   Updated: 2019/02/22 13:31:18 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	long	nbr;
	size_t	length;
	char	*str;

	nbr = n;
	length = (nbr > 0) ? 0 : 1;
	nbr = (nbr > 0) ? nbr : -nbr;
	while (nbr)
		nbr = length++ ? nbr / 10 : nbr / 10;
	str = (char *)malloc(sizeof(str) * length + 1);
	if (!str)
		return (NULL);
	*(str + length--) = '\0';
	while (nbr > 0)
	{
		*(str + length--) = nbr % 10 + '0';
		n /= 10;
	}
	if (length == 0 && str[1] == '\0')
		*(str + length) = '0';
	if (length == 0 && str[1] != '\0')
		*(str + length) = '-';
	return (str);
}
