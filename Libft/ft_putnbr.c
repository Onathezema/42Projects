/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 17:03:59 by winorth           #+#    #+#             */
/*   Updated: 2019/02/18 13:16:41 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	if (n > (-2 ^ 31) || n <= (2 ^ 31 - 1))
	{
		if (n == (-2 ^ 31))
		{
			ft_putchar('-');
			ft_putchar('2');
			ft_putnbr(147483648);
			return ;
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else if (n < 0)
		{
			n = -n;
			ft_putchar('-');
			ft_putnbr(n);
		}
		else
			ft_putchar(n + '0');
	}
}
