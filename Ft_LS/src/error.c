/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:43:28 by winorth           #+#    #+#             */
/*   Updated: 2019/09/05 16:27:19 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_ls.h"

int	printerror(char *dirp, int errnum)
{
	ft_dprintf(2, "ft_ls: %s: %s\n", dirp, strerror(errnum));
	return (errnum);
}

int	error_flags(char err)
{
	ft_dprintf(2, "ft_ls: illegal option --%c\n", err);
	ft_dprintf(2, "usage: ft_ls [-AFGHRadfglortu1] [file ...]\n");
	return (-1);
}

int	inputtest(char *inp, int flags)
{
	char		*fix;
	struct stat	ltest;
	struct stat	test;

	fix = ft_strlen(inp) ? ft_strdup(inp) : ft_strdup("./");
	lstat(inp, &ltest);
	stat(inp, &test);
	free(fix);
	if (errno)
	{
		printerror(inp, errno);
		errno = 0;
		return (1);
	}
	if (flags & HH)
		return (0);
	if (flags & dd || ((flags & LL && type(ltest, S_IFLNK) &&
					(inp[ft_strlen(inp) - 1] != '/' ||
					(*inp == '\'' && inp[ft_strlen(inp) - 2] != '/'))) ||
				!type(test, S_IFDIR)))
		return (2);
	return (0);
}
