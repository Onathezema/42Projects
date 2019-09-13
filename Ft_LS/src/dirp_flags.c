/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dirp_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:15 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 16:26:51 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"
#include "../include/flagtypes.h"

static char	**arrjoin(char **str, char *word)
{
	char	**new;
	char	**old;
	int		i;

	old = str;
	new = NULL;
	i = 0;
	while (old[i])
		i++;
	if ((new = (char **)malloc(sizeof(char *) * (i + 2))))
	{
		i = -1;
		while (old[++i])
			new[i] = old[i];
		new[i++] = word;
		new[i] = NULL;
	}
	free(str);
	return (new);
}

char		**getdirp(int s, char **in, int flags)
{
	char	**dirps;
	int		i;
	int		err;

	i = 1;
	dirps = (char **)malloc(sizeof(char *));
	*dirps = NULL;
	err = 0;
	while (in[i] && *in[i] == '-')
		i++;
	while (i < s)
	{
		err = inputtest(in[i], flags);
		if (!err)
			dirps = arrjoin(dirps, ft_strdup(in[i]));
		else if (err == 2)
			print_one(in[i], flags);
		i++;
	}
	if (!*dirps && !err)
		dirps = arrjoin(dirps, ft_strdup("./"));
	return (dirps);
}

int			oneflag(int flag)
{
	if (flag & LL)
		flag -= LL;
	if (flag & gg)
		flag -= gg;
	flag |= 1;
	return (flag);
}

int			getflag(char *str)
{
	int	flag;
	int	i;

	flag = 0;
	i = 0;
	if (*str++ == '-')
	{
		while (*str)
		{
			if (*str == '1')
				flag = oneflag(flag);
			while (i <= 14 && g_flagtypes[i].type != *str)
				i++;
			if (i <= 14)
				flag |= g_flagtypes[i].flag;
			else
				return (error_flags(*str));
			str++;
			i = 0;
		}
	}
	return (flag);
}

int			getflags(char **str, int s)
{
	int	flags;
	int	i;

	flags = 0;
	i = 0;
	while (++i < s)
	{
		if (*str[i] != '-')
			break ;
		flags |= getflag(str[i]);
	}
	return (flags);
}
