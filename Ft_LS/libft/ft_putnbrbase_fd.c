/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrbase_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 18:22:15 by winorth           #+#    #+#             */
/*   Updated: 2019/07/29 18:22:17 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrbase_fdinner(uintmax_t nbr, char *base, size_t baselen,
		int fd)
{
	if (nbr >= baselen)
	{
		ft_putnbrbase_fdinner(nbr / baselen, base, baselen, fd);
		ft_putnbrbase_fdinner(nbr % baselen, base, baselen, fd);
	}
	else
		ft_putchar_fd(base[nbr], fd);
}

void		ft_putnbrbase_fd(uintmax_t nbr, char *base, int fd)
{
	ft_putnbrbase_fdinner(nbr, base, ft_strlen(base), fd);
}
