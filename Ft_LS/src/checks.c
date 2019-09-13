/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:00 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 14:45:41 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

void	deldirp(char **dirp)
{
	int		i;

	i = 0;
	while (dirp[i])
		free(dirp[i++]);
	free(dirp);
}

int		fit(int ex, t_dips *d, int col)
{
	int		i;
	t_dips	*curr;

	i = 1;
	curr = d;
	while (curr)
	{
		if (!(++i % col) && (int)ft_strlen(d->name) > ex)
			return (0);
		curr = curr->next;
	}
	return (1);
}

int		type(struct stat stats, unsigned int type)
{
	if ((stats.st_mode & S_IFMT) == type)
		return (1);
	return (0);
}

int		end(t_dips *dir)
{
	while (dir)
	{
		if (type(*(dir->stats), S_IFDIR))
			return (0);
		dir = dir->next;
	}
	return (1);
}
