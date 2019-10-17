/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 11:49:50 by winorth           #+#    #+#             */
/*   Updated: 2019/10/09 18:36:16 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../include/ft_ssl.h"

void	usage(void)
{
	char const	*pname;

	if ((pname = ft_strchr(g_pname, '/')))
		++pname;
	else
		pname = g_pname;
	ft_dprintf(STDERR_FILENO,
			"usage: %s <digest> [-pqr] [-s string] [files ...]\n", pname);
	ft_dprintf(STDERR_FILENO, "\nMessage Digest commands:\nmd5\nsha256\n");
	exit(1);
}

void	rev_endian32(uint32_t *tab, int len)
{
	unsigned char	*data;
	uint32_t		n;
	int				i;

	i = 0;
	while (i < len)
	{
		n = tab[i];
		data = (unsigned char *)&tab[i++];
		data[0] = ((n >> 24) & 0xff);
		data[1] = ((n >> 16) & 0xff);
		data[2] = ((n >> 8) & 0xff);
		data[3] = (n & 0xff);
	}
}

void	rev_endian64(uint64_t *tab, int len)
{
	unsigned char	*data;
	uint64_t		n;
	int				i;

	i = 0;
	while (i < len)
	{
		n = tab[i];
		data = (unsigned char *)&tab[i++];
		data[0] = ((n >> 56) & 0xff);
		data[1] = ((n >> 48) & 0xff);
		data[2] = ((n >> 40) & 0xff);
		data[3] = ((n >> 32) & 0xff);
		data[4] = ((n >> 24) & 0xff);
		data[5] = ((n >> 16) & 0xff);
		data[6] = ((n >> 8) & 0xff);
		data[7] = (n & 0xff);
	}
}
