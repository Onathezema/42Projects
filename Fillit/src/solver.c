/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: winorth <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 13:17:19 by winorth           #+#    #+#             */
/*   Updated: 2019/05/31 15:19:11 by winorth          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Backtracking implementation of the solver.
*/

int		solve_map(t_map *map, t_list *list)
{
	int		x;
	int		y;
	t_etris	*tetri;

	if (list == NULL)
		return (1);
	y = -1;
	tetri = (t_etris *)(list->content);
	while (++y < map->size - tetri->height + 1)
	{
		x = -1;
		while (++x < map->size - tetri->width + 1)
		{
			if (place(tetri, map, x, y))
			{
				if (solve_map(map, list->next))
					return (1);
				else
					set_piece(tetri, map, point_new(x, y), '.');
			}
		}
	}
	return (0);
}

/*
** Gets the rounded up sqrt of a number. Equivalent to ceil(sqrt(n)).
*/

int		high_sqrt(int n)
{
	int	size;

	size = 2;
	while (size * size < n)
		size++;
	return (size);
}

/*
** Tries to solve maps starting from the smallest possible size.
*/

t_map	*solve(t_list *list)
{
	t_map	*map;
	int		size;

	size = high_sqrt(ft_lstcount(list) * 4);
	map = map_new(size);
	while (!solve_map(map, list))
	{
		size++;
		free_map(map);
		map = map_new(size);
	}
	return (map);
}
