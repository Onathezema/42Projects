/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:17:51 by winorth           #+#    #+#             */
/*   Updated: 2019/05/31 15:22:40 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Frees an allocated map structure.
*/

void	free_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_memdel((void **)&(map->array[i]));
		i++;
	}
	ft_memdel((void **)&(map->array));
	ft_memdel((void **)&map);
}

/*
** Prints an allocated map structure to standard output.
*/

void	print_map(t_map *map)
{
	int i;

	i = 0;
	while (i < map->size)
	{
		ft_putstr(map->array[i]);
		ft_putchar('\n');
		i++;
	}
}

/*
** Allocates a new map structure with specified size.
*/

t_map	*map_new(int size)
{
	t_map	*map;
	int		i;
	int		j;

	map = (t_map *)ft_memalloc(sizeof(t_map));
	map->size = size;
	map->array = (char **)ft_memalloc(sizeof(char *) * size);
	i = -1;
	while (++i < size)
	{
		map->array[i] = ft_strnew(size);
		j = -1;
		while (++j < size)
			map->array[i][j] = '.';
	}
	return (map);
}

/*
** Places a tetrimino on map at specified position,
** checking if the placement is possible.
*/

int		place(t_etris *tetri, t_map *map, int x, int y)
{
	int i;
	int j;

	i = 0;
	while (i < tetri->width)
	{
		j = 0;
		while (j < tetri->height)
		{
			if (tetri->pos[j][i] == '#' && map->array[y + j][x + i] != '.')
				return (0);
			j++;
		}
		i++;
	}
	set_piece(tetri, map, point_new(x, y), tetri->value);
	return (1);
}

/*
** Sets a tetrimino on a map at a position with the specified character.
** To place, call with c = tetri->value. To remove, call with c= '.'.
*/

void	set_piece(t_etris *tetri, t_map *map, t_point *point, char c)
{
	int i;
	int j;

	i = -1;
	while (++i < tetri->width)
	{
		j = -1;
		while (++j < tetri->height)
		{
			if (tetri->pos[j][i] == '#')
				map->array[point->y + j][point->x + i] = c;
		}
	}
	ft_memdel((void **)&point);
}
