/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filetypes.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:21:14 by winorth           #+#    #+#             */
/*   Updated: 2019/09/11 12:38:15 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILETYPES_H
# define FILETYPES_H

# include "ft_ls.h"

t_filetypes g_filetypes[] =
{
	{S_IFIFO, 'p', "\033[0;33m", '|'},
	{S_IFDIR, 'd', "\033[0;34.", '/'},
	{S_IFBLK, 'b', "\033[0;34;46m", '\0'},
	{S_IFLNK, 'l', "\033[0;35m", '@'},
	{S_IFSOCK, 's', "\033[0;32m", '='},
	{S_IFREG, '-', "\033[0m", '\0'},
	{S_IFWHT, '-', "\033[0m", '%'},
	{S_IFCHR, 'c', "\033[0;34;43m", '\0'},
	{S_ISUID, '-', "\033[0;30;41m", '\0'},
	{S_ISGID, '-', "\033[0;30;46m", '\0'},
	{S_ISVTX, '-', "\033[0m", '\0'},
	{S_IRUSR, '-', "\033[0m", '\0'},
	{S_IWUSR, '-', "\033[0m", '\0'},
	{S_IXUSR, '-', "\033[0;31m", '*'},
	{S_IWOTH, '-', "\033[0;30;42m", '\0'},
	{S_IWOTH, '-', "\033[0;30;43m", '\0'}
};

/*
** normal text is white,
** directories are blue,
** executable is red,
** symbolic link magenta,
** socket is green,
** pipe (fifo) is brown,
** block (b) cyan and blue,
** executable with set uid is black/red,
** executable with set gid is black/cyan,
** directory writable to others sticky is black/green,
** directory writable no sticky is black/brown
** character special file grey/yellow
*/

#endif
