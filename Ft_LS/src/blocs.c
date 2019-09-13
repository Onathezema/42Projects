/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blocs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:42:47 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 14:47:54 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"
#include "../include/filetypes.h"

void	blocs(t_dips *dir)
{
	int		blocs;

	blocs = 0;
	while (dir)
	{
		while (dir->next && !(dir->flags & aa) && *(dir->name) == '.')
			dir = dir->next;
		blocs += dir->stats->st_blocks;
		dir = dir->next;
	}
	ft_printf("total %d\n", blocs);
}

int		pchar(t_dips *d, int i, int width)
{
	int		j;

	j = i;
	if (i == 3 && (d->flags & LL || d->flags & gg || d->flags & oo))
	{
		if (type(*d->stats, S_IFDIR))
		{
			j = 1;
			plink(d);
		}
	}
	else if (i == 8 || i == 9)
		j = 13;
	ft_printf("%c", g_filetypes[j].c2);
	if (g_filetypes[j].c2)
		width--;
	if (i == 3 && j != 1 && (d->flags & LL || d->flags & gg))
		plink(d);
	return (width);
}

void	pname(t_dips *d, int i, int width)
{
	int		len;

	if (d->flags & GG)
		ft_printf("%s", g_filetypes[i].color);
	ft_printf("%s", d->name);
	if (d->flags & GG)
		ft_printf("{eoc}");
	len = ft_strlen(d->name);
	width = width > len ? width - len : 0;
	i = (i == 14 || i == 15) ? 1 : i;
	if (d->flags & FF)
		width = pchar(d, i, width);
	else if (((d->flags & LL) || (d->flags & gg)) && g_filetypes[i].c == 'l')
		plink(d);
	while (width--)
		ft_putchar(' ');
}

void	ptype(t_dips *d, int width)
{
	int		i;

	i = 0;
	while (i < 15 && !type(*d->stats, g_filetypes[i].type))
		i++;
	if (i == 5 && d->stats->st_mode & S_IXUSR)
		i = 13;
	if (i == 13)
	{
		if (d->stats->st_mode & S_ISUID)
			i = 8;
		else if (d->stats->st_mode & S_ISGID)
			i = 9;
	}
	if (d->flags & LL || d->flags & gg)
	{
		ft_printf("%c", g_filetypes[i].c);
		pinfo(d);
	}
	if (i == 1 && d->stats->st_mode & S_IWOTH)
		i = d->stats->st_mode & S_ISVTX ? 14 : 15;
	pname(d, i, width);
}

void	print_mm(t_dips *d)
{
	if (type(*d->stats, S_IFCHR) || type(*d->stats, S_IFBLK))
		ft_printf("  %3d, %3d", major(d->stats->st_rdev),
				minor(d->stats->st_rdev));
	else
		ft_printf("  %8ld", d->size);
}
