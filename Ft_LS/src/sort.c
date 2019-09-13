/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:44:08 by winorth           #+#    #+#             */
/*   Updated: 2019/09/04 19:33:13 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		sorted(char *str1, char *str2)
{
	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	if (*str1 <= *str2)
		return (rr);
	return (0);
}

int		tsorted(t_dips *dirp1, t_dips *dirp2)
{
	struct stat	str1;
	struct stat	str2;

	str1 = *dirp1->stats;
	str2 = *dirp2->stats;
	if (str1.st_mtimespec.tv_sec < str2.st_mtimespec.tv_sec)
		return (tt);
	else if (str1.st_mtimespec.tv_sec == str2.st_mtimespec.tv_sec)
	{
		if (str1.st_mtimespec.tv_nsec < str2.st_mtimespec.tv_nsec)
			return (tt);
		else if (str1.st_mtimespec.tv_nsec == str2.st_mtimespec.tv_nsec)
			return (sorted(dirp1->name, dirp2->name) ? tt : 0);
	}
	return (0);
}

void	fsort(t_dips **lst)
{
	t_dips		*dirp;
	t_dips		*last;

	dirp = *lst;
	last = NULL;
	while (dirp->next)
	{
		if (!(ft_strcmp(dirp->next->name, ".") &&
					ft_strcmp(dirp->next->name, "..")) &&
				!sorted(dirp->name, dirp->next->name))
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
}

void	tsort(t_dips **lst)
{
	t_dips		*dirp;
	t_dips		*last;

	dirp = *lst;
	last = NULL;
	while (!(ft_strcmp(".", dirp->name) && ft_strcmp("..", dirp->name)))
		dirp = dirp->next;
	while (dirp->next)
	{
		if ((tt & dirp->flags)
				== tsorted(dirp, dirp->next))
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
}

void	dirsort(t_dips **lst)
{
	t_dips		*dirp;
	t_dips		*last;

	dirp = *lst;
	last = NULL;
	while (dirp->next)
	{
		if ((rr & dirp->flags) ==
				sorted(dirp->name, dirp->next->name))
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
}
