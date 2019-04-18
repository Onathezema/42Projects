/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 14:17:08 by winorth           #+#    #+#             */
/*   Updated: 2019/04/16 14:22:27 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		main(int argc, char **argv)
{
	char	*line;
	int		fd;
	int		i;

	line = NULL;
	i = 1;
	if (argc == 1)
	{
		fd = open(0, O_RDONLY);
		while (get_next_line(0, &line) > 0)
		{
			ft_putstr(line);
			ft_putchar('\n');
			ft_memdel((void **)&line);
		}
		ft_memdel((void **)&line);
	}
	else
	{
		while (argv[i])
		{
			fd = open(argv[i], O_RDONLY);
			while (get_next_line(fd, &line) > 0)
			{
				ft_putstr(line);
				ft_putchar('\n');
				ft_memdel((void **)&line);
			}
			ft_memdel((void **)&line);
			i++;
		}
	}
	return (0);
}
