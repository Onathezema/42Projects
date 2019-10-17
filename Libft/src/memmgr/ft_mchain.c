/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mchain.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/02 14:40:58 by winorth           #+#    #+#             */
/*   Updated: 2019/10/08 19:27:43 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/ft_memmgr.h"
#include <stdint.h>
#include <stdlib.h>

int			ft_mcdel(t_mchain *mchain)
{
	t_mchain		**mchead;
	t_mchain		*next_chain;
	t_mlink			*next_link;
	int				count;

	if (!mchain)
		return (-1);
	count = 0;
	while (mchain->start)
	{
		next_link = mchain->start->next;
		if (CANFREE(mchain->start))
			free(mchain->start->ptr);
		free(mchain->start);
		mchain->start = next_link;
		++count;
	}
	mchead = ft_mcgetall();
	while (*mchead && *mchead != mchain)
		mchead = &(*mchead)->next;
	next_chain = mchain->next;
	free(mchain);
	*mchead = next_chain;
	return (count);
}

int			ft_mcdelall(void)
{
	t_mchain		**mchain;
	t_mchain		*next_chain;
	t_mlink			*next_link;
	int				count;

	mchain = ft_mcgetall();
	count = 0;
	while (*mchain)
	{
		while ((*mchain)->start)
		{
			next_link = (*mchain)->start->next;
			if (CANFREE((*mchain)->start))
				free((*mchain)->start->ptr);
			free((*mchain)->start);
			(*mchain)->start = next_link;
			++count;
		}
		next_chain = (*mchain)->next;
		free(*mchain);
		*mchain = next_chain;
	}
	return (count);
}

t_mchain	*ft_mcget(const char *label)
{
	t_mchain	**mchain;

	mchain = ft_mcgetall();
	while (*mchain && ft_strcmp(label, (*mchain)->label))
		mchain = &(*mchain)->next;
	if (!*mchain)
	{
		if (!(*mchain = (t_mchain *)ft_memalloc(sizeof(t_mchain))))
			return (NULL);
		ft_stpncpy((*mchain)->label, label, 26);
	}
	return (*mchain);
}

t_mchain	**ft_mcgetall(void)
{
	static t_mchain *head;

	return (&head);
}

int			ft_mcexists(const char *label)
{
	t_mchain	**mchain;

	mchain = ft_mcgetall();
	while (*mchain && ft_strcmp(label, (*mchain)->label))
		mchain = &(*mchain)->next;
	return (*mchain != NULL);
}
