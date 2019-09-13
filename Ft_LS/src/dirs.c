/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:22 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 16:56:15 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int		adddir(t_dips **dir, struct dirent *ent)
{
	t_dips		*new;

	if (!ent)
		return (0);
	new = *dir;
	while (new->next)
		new = new->next;
	new->next = newdir(ent->d_name, new->dirp, new->flags);
	return (1);
}

void	dirpfill(t_dips **dir)
{
	t_dips		*new;
	struct stat	*stats;

	new = *dir;
	stats = new->stats;
	new->user = huid(stats->st_uid);
	new->group = hgid(stats->st_gid);
	new->userlen = ft_strlen(new->user);
	new->grouplen = ft_strlen(new->group);
	new->size_pad = numlength(new->size);
	new->link_pad = numlength(stats->st_nlink);
}

t_dips	*newdir(char *name, char *path, int flags)
{
	t_dips		*new;
	struct stat	*stats;
	char		*dirp;

	if ((*name == '.' && !(flags & aa)) || ((!ft_strcmp(name, ".")
					|| !ft_strcmp(name, "..")) && flags & AA))
		return (NULL);
	dirp = inputfix(path);
	dirp = (*name == '.' && (name[1] == '.' || name[1] == '/')) ?
		ft_swapnfree(ft_strdup(name), &dirp) :
		ft_swapnfree(ft_strjoin(dirp, name), &dirp);
	stats = (struct stat *)malloc(sizeof(struct stat));
	lstat(dirp, stats);
	if (!(new = (t_dips *)malloc(sizeof(t_dips))))
		return (NULL);
	new->name = ft_strdup(name);
	new->size = stats->st_size;
	new->stats = stats;
	new->flags = flags;
	new->dirp = path;
	new->next = NULL;
	dirpfill(&new);
	free(dirp);
	return (new);
}

void	dirdel(t_dips *dir)
{
	t_dips		*del;

	del = dir;
	free(dir->name);
	free(dir->stats);
	free(dir->group);
	free(dir->user);
	if (del->next)
		dirdel(del->next);
	free(del);
}

void	dirpswap(t_dips **curr)
{
	t_dips		*temp;

	temp = (*curr)->next->next;
	(*curr)->next->next = (*curr);
	(*curr)->next = temp;
}
