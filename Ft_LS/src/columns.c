/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:06 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 14:54:13 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	peveryi(t_dips *d, int i, int len)
{
	t_dips		*curr;
	int			count;

	count = 1;
	ptype(d, len);
	curr = d->next;
	while (curr)
	{
		if (!(count % i))
			ptype(curr, len);
		curr = curr->next;
		count++;
	}
}

void	pcols(t_dips *d, int cols, int size, int len)
{
	int		counter;
	int		i;

	counter = 1;
	i = size / cols;
	if (size % cols)
		i++;
	while (counter <= i)
	{
		peveryi(d, i, len);
		d = d->next;
		counter++;
		ft_putchar('\n');
	}
}

void	countcol(t_dips *d, int len, int count)
{
	struct winsize	ws;
	int				size;
	int				cols;

	cols = 1;
	ioctl(1, TIOCGWINSZ, &ws);
	size = ws.ws_col;
	if (size > len)
	{
		cols = size / len;
	}
	pcols(d, cols, count, len);
}

int		checklen(int len, int cmp)
{
	if (len <= cmp)
	{
		len = cmp >= 8 ? 16 : len;
		len = cmp >= 16 ? 32 : len;
		len = cmp >= len ? cmp + 8 : len;
	}
	return (len);
}

void	pcol(t_dips *d)
{
	t_dips		*begin;
	int			len;
	int			count;
	t_rec		*recs;

	if (!d)
		return ;
	len = 8;
	count = 0;
	begin = d;
	recs = NULL;
	if (d->flags & RR)
		recs = recnew(NULL);
	while (d)
	{
		count++;
		len = checklen(len, ft_strlen(d->name));
		if (d->flags & RR && !ft_strequ(d->name, ".") &&
				!ft_strequ(d->name, "..") && type(*d->stats, S_IFDIR))
			recadd(d, &recs);
		d = d->next;
	}
	countcol(begin, len, count);
	chec_recur(&recs);
	recdel(recs);
}
