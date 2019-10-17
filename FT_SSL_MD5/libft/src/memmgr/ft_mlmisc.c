/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlmisc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 12:07:26 by winorth           #+#    #+#             */
/*   Updated: 2019/10/10 15:08:16 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memmgr.h"

void	*ft_mlalloc(t_mchain *mchain, size_t size)
{
	void		*ptr;

	if (!(ptr = ft_memalloc(size)))
		return (NULL);
	if (!ft_mladd(mchain, ptr, size))
	{
		free(ptr);
		return (NULL);
	}
	return (ptr);
}

t_mlink	*ft_mlrev(t_mchain *mchain)
{
	t_mlink		*curr;
	t_mlink		*prev;
	t_mlink		*next;

	if (!(curr = mchain->start))
		return (NULL);
	if (mchain->end == curr)
		return (curr);
	mchain->end = curr;
	prev = NULL;
	while (TRUE)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		if (!next)
			break ;
		curr = next;
	}
	return ((mchain->start = curr));
}

t_mlink	*ft_mlpop(t_mchain *mchain)
{
	t_mlink		*next;

	if (!mchain->start)
		return (NULL);
	if (mchain->end == mchain->start)
		mchain->end = NULL;
	next = mchain->start->next;
	if (CANFREE(mchain->start))
		free(mchain->start->ptr);
	free(mchain->start);
	mchain->link_count--;
	return ((mchain->start = next));
}

t_mlink	*ft_mladd(t_mchain *mchain, void *ptr, size_t size)
{
	t_mlink		*mlink;

	if (!(mlink = (t_mlink *)ft_memalloc(sizeof(t_mlink))))
		return (NULL);
	mlink->mchain = mchain;
	mlink->ptr = ptr;
	mlink->size = size;
	mlink->next = mchain->start;
	mchain->start = mlink;
	if (!mchain->end)
		mchain->end = mlink;
	mchain->link_count++;
	return (mlink);
}
