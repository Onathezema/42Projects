/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <winorth@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 17:54:41 by winorth           #+#    #+#             */
/*   Updated: 2019/04/16 14:37:56 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	lbr_or_zerochar(char *str)
{
	size_t	dis;

	dis = 0;
	while (str[dis] != '\n' && str[dis] != '\0')
		dis++;
	return (dis);
}

static void		str_cleancopy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i <= BUFF_SIZE)
	{
		dest[i] = '\0';
		i++;
	}
}

static char		*joinstr(char **line, const char *buf, size_t n)
{
	char	*new;
	char	*tmp;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	tmp = *line;
	if (!(new = ft_strnew(ft_strlen(tmp) + n + 1)))
		return (NULL);
	while (tmp[i])
	{
		new[i] = tmp[i];
		i++;
	}
	while (buf[j] && n)
	{
		new[i] = buf[j];
		i++;
		j++;
		n--;
	}
	free(tmp);
	return (new);
}

static int		finish(char **line, char *buf_fd, size_t dist)
{
	if (buf_fd[dist] == '\n' || (buf_fd[0] == '\0' && *line[0]) != '\0')
	{
		if (buf_fd[dist] == '\n')
			str_cleancopy(buf_fd, &(buf_fd[dist + 1]));
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	int				result;
	size_t			dist;
	static char		buf[FOPEN_MAX][BUFF_SIZE + 1];

	if (fd < 0 || !line || fd > FOPEN_MAX)
		return (-1);
	if (!(*line = ft_strnew(1)))
		return (-1);
	result = 1;
	while (result > 0)
	{
		if (buf[fd][0] == '\0')
			if ((result = read(fd, &buf[fd], BUFF_SIZE)) < 0)
				return (result);
		dist = lbr_or_zerochar(buf[fd]);
		*line = joinstr(line, buf[fd], dist);
		if (finish(line, buf[fd], dist))
			return (1);
		ft_strclr((char *)&buf[fd]);
	}
	return (0);
}
