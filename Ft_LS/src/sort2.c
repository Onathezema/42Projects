/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:44:12 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 14:51:52 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		usorted(t_dips *dirp1, t_dips *dirp2)
{
	struct stat	str1;
	struct stat	str2;

	str1 = *dirp1->stats;
	str2 = *dirp2->stats;
	if (str1.st_atimespec.tv_sec < str2.st_atimespec.tv_sec)
		return (uu);
	else if (str1.st_atimespec.tv_sec == str2.st_atimespec.tv_sec)
	{
		if (str1.st_atimespec.tv_nsec < str2.st_atimespec.tv_nsec)
			return (uu);
		else if (str1.st_atimespec.tv_nsec == str2.st_atimespec.tv_nsec)
			return (sorted(dirp1->name, dirp2->name) ? uu : 0);
	}
	return (0);
}

void	usort(t_dips **lst)
{
	t_dips		*dirp;
	t_dips		*last;

	dirp = *lst;
	last = NULL;
	while (dirp->next)
	{
		if ((rr & dirp->flags) ==
				usorted(dirp, dirp->next))
		{
			if (dirp != *lst)
				last->next = dirp->next;
			else
				*lst = dirp->next;
			dirpswap(&dirp);
			dirp = *lst;
		}
		else
		{
			last = dirp;
			dirp = dirp->next ? dirp->next : dirp;
		}
	}
	fsort(lst);
}

void	sorting(t_dips **dirp, int flags)
{
	if (!(flags & ff))
	{
		if (flags & tt)
			tsort(dirp);
		else if (flags & uu)
			usort(dirp);
		else
			dirsort(dirp);
	}
	else
		fsort(dirp);
	sizepad_fix(dirp, (*dirp)->size_pad);
	userlen_fix(dirp, (*dirp)->userlen);
	grouplen_fix(dirp, (*dirp)->grouplen);
	linkpad_fix(dirp, (*dirp)->link_pad);
}
