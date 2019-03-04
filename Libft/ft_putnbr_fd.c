/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 12:56:43 by winorth           #+#    #+#             */
/*   Updated: 2019/02/19 14:52:53 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	if (n > (-2 ^ 31) || n <= (2 ^ 31 - 1))
	{
		if (n == (-2 ^ 31))
		{
			ft_putstr_fd("-2147483648", fd);
			return ;
		}
		else if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		else
			ft_putchar_fd(n + '0', fd);
	}
}
