/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recur.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:44:03 by winorth           #+#    #+#             */
/*   Updated: 2019/09/04 20:36:40 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

t_rec	*recnew(t_dips *dirp)
{
	t_rec	*new;

	new = (t_rec *)malloc(sizeof(t_rec));
	new->direc = dirp;
	new->next = NULL;
	return (new);
}

void	recadd(t_dips *dirp, t_rec **rec)
{
	t_rec	*curr;
	t_rec	*new;

	curr = *rec;
	if (!(curr->direc))
	{
		curr->direc = dirp;
		return ;
	}
	new = recnew(dirp);
	while (curr->next)
		curr = curr->next;
	curr->next = new;
}

void	recdel(t_rec *rec)
{
	t_rec		*del;

	del = rec;
	if (del && del->next)
		recdel(del->next);
	if (del)
		free(del);
}

char	*hgid(gid_t st_gid)
{
	struct group *id;

	id = getgrgid(st_gid);
	return (id ? ft_strdup(id->gr_name) : NULL);
}

char	*huid(uid_t st_uid)
{
	struct passwd *id;

	id = getpwuid(st_uid);
	return (id ? ft_strdup(id->pw_name) : NULL);
}
