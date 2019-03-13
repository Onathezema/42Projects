/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:03:59 by winorth           #+#    #+#             */
/*   Updated: 2019/03/13 13:53:41 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n == INT_MIN)
		return (ft_putstr("-2147483648"));
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10 + 0);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n);
	}
	else
		ft_putchar(n + '0');
}
