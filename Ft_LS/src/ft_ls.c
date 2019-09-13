/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 14:45:31 by winorth           #+#    #+#             */
/*   Updated: 2019/09/09 14:25:24 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

char	*inputfix(char *in)
{
	char	*str;

	str = ft_strdup(in);
	if (*str != '.' && *str != '/')
		str = ft_swapnfree(ft_strjoin("./", str), &str);
	if (str[ft_strlen(str) - 1] != '/')
		str = ft_swapnfree(ft_strjoin(str, "/"), &str);
	return (str);
}

void	chec_recur(t_rec **recur)
{
	char	*fdirp;
	t_rec	*current;
	t_dips	*direc;

	current = *recur;
	if (!current || !current->direc)
		return ;
	while (current && current->direc)
	{
		direc = current->direc;
		fdirp = ft_strjoin(direc->dirp, direc->name);
		ft_printf("\n%s\n", fdirp);
		ft_ls(inputfix(fdirp), direc->flags);
		free(fdirp);
		current = current->next;
	}
}

t_dips	*readdirec(char *dirp, DIR *str, int flags)
{
	struct dirent	*ent;
	t_dips			*dirs;

	ent = NULL;
	dirs = NULL;
	while (!dirs && str && (ent = readdir(str)))
		dirs = newdir(ent->d_name, dirp, flags);
	if (dirs)
	{
		while (dirs && adddir(&dirs, readdir(str)))
			continue ;
		sorting(&dirs, flags);
	}
	return (dirs);
}

int		ft_ls(char *dirp, int flags)
{
	t_dips	*dirs;
	DIR		*str;

	if (!(str = opendir(dirp)) && errno)
	{
		free(dirp);
		return (errno);
	}
	dirs = readdirec(dirp, str, flags);
	closedir(str);
	if (dirs)
	{
		flags & 1 || flags & LL || flags & oo || dirs->flags & gg
			? plist(dirs) : pcol(dirs);
		dirdel(dirs);
	}
	free(dirp);
	return (0);
}

int		main(int argc, char **argv)
{
	char	**dirp;
	int		size;
	int		flags;
	int		i;

	errno = 0;
	flags = getflags(argv, argc);
	if (flags == -1)
		return (1);
	dirp = getdirp(argc, argv, flags);
	size = 0;
	i = 0;
	while (dirp[size])
		size++;
	while (dirp[i])
	{
		if (size > 1 && ft_strcmp(dirp[i], "./"))
			ft_printf("%s:\n", dirp[i]);
		if (ft_ls(inputfix(dirp[i]), flags))
			printerror(dirp[i], errno);
		if (++i < size)
			ft_putchar('\n');
	}
	deldirp(dirp);
	return (errno);
}
