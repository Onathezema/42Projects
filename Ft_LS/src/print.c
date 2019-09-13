/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:59 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 14:43:37 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	ptime(struct stat *info)
{
	char	*time;

	time = ft_strsub(ctime(&(info->st_mtimespec.tv_sec)), 4, 12);
	ft_printf(" %s ", time);
	free(time);
}

void	pperm(struct stat *info, int b)
{
	while (b)
	{
		b & info->st_mode ? ft_printf("r") : ft_printf("-");
		b >>= 1;
		b & info->st_mode ? ft_printf("w") : ft_printf("-");
		b >>= 1;
		if (b & info->st_mode || info->st_mode & S_ISUID ||
				info->st_mode & S_ISVTX)
		{
			if (!(b & info->st_mode))
				ft_printf("S");
			else if ((b == 64 && info->st_mode & S_ISUID)
					|| (b == 8 && info->st_mode & S_ISGID))
				ft_printf("s");
			else if (b == 1 && info->st_mode & S_ISVTX)
				b & info->st_mode ? ft_printf("t") : ft_printf("T");
			else
				ft_printf("x");
		}
		else
			ft_printf("-");
		b >>= 1;
	}
}

void	pinfo(t_dips *d)
{
	int		b;

	b = 256;
	pperm(d->stats, b);
	ft_printf("  %*d ", d->link_pad, d->stats->st_nlink);
	if (!(d->flags & gg))
		d->user ? ft_printf("%-*s", d->userlen, d->user) :
			ft_printf("%*d", d->userlen, d->stats->st_uid);
	if (!(d->flags & gg) && !(d->flags & oo))
		ft_printf("  ");
	if (!(d->flags & oo))
		d->group ? ft_printf("%-*s", d->grouplen, d->group) :
			ft_printf("%*d", d->grouplen, d->stats->st_gid);
	if (ft_strstr(d->dirp, "/dev"))
		print_mm(d);
	else
		ft_printf("  %*ld", d->size_pad, d->size);
	ptime(d->stats);
}

void	plink(t_dips *d)
{
	char	link[PATH_MAX + 1];
	int		res;
	char	*dirp;

	dirp = ft_strjoin(d->dirp, d->name);
	res = readlink(dirp, link, PATH_MAX);
	link[res] = '\0';
	ft_printf(" -> %s", link);
	free(dirp);
}

void	plist(t_dips *d)
{
	t_rec	*recs;

	recs = NULL;
	if (!d)
		return ;
	if (d->flags & LL || d->flags & gg)
		blocs(d);
	if (d->flags & RR)
		recs = recnew(NULL);
	while (d)
	{
		ptype(d, 1);
		ft_putchar('\n');
		if (d->flags & RR && !ft_strequ(d->name, ".") &&
				!ft_strequ(d->name, "..") && type(*d->stats, S_IFDIR))
			recadd(d, &recs);
		d = d->next;
	}
	chec_recur(&recs);
	recdel(recs);
}
