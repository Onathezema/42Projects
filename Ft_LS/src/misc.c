/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:45 by winorth           #+#    #+#             */
/*   Updated: 2019/09/04 20:00:57 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	userlen_fix(t_dips **dir, int size)
{
	t_dips	*dirp;

	dirp = *dir;
	while (dirp)
	{
		if (dirp->userlen > size)
		{
			userlen_fix(dir, dirp->userlen);
			return ;
		}
		dirp->userlen = size;
		dirp = dirp->next;
	}
}

void	grouplen_fix(t_dips **dir, int size)
{
	t_dips	*dirp;

	dirp = *dir;
	while (dirp)
	{
		if (dirp->grouplen > size)
		{
			grouplen_fix(dir, dirp->grouplen);
			return ;
		}
		dirp->grouplen = size;
		dirp = dirp->next;
	}
}

void	linkpad_fix(t_dips **dir, int size)
{
	t_dips	*dirp;

	dirp = *dir;
	while (dirp)
	{
		if (dirp->link_pad > size)
		{
			linkpad_fix(dir, dirp->link_pad);
			return ;
		}
		dirp->link_pad = size;
		dirp = dirp->next;
	}
}

void	sizepad_fix(t_dips **dir, int size)
{
	t_dips	*dirp;

	dirp = *dir;
	while (dirp)
	{
		if (dirp->size_pad > size)
		{
			sizepad_fix(dir, dirp->size_pad);
			return ;
		}
		dirp->size_pad = size;
		dirp = dirp->next;
	}
}
