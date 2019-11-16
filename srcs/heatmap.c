/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heatmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:06:24 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/12 02:16:36 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	horizontal_axis(t_map *map, int y, int x, int prior)
{
	int init_y;
	int init_p;

	init_y = y;
	init_p = prior;
	while (y >= 0)
	{
		if (prior < map->heatarr[y][x] ||
				map->heatarr[y][x] == 0 || map->heatarr[y][x] == -1)
			map->heatarr[y][x] = prior;
		y--;
		prior++;
	}
	prior = init_p;
	y = init_y;
	while (y < map->y)
	{
		if (prior < map->heatarr[y][x] ||
				map->heatarr[y][x] == 0 || map->heatarr[y][x] == -1)
			map->heatarr[y][x] = prior;
		y++;
		prior++;
	}
}

static void	vertical_axis(t_map *map, int y, int x, int prior)
{
	int init_x;
	int init_p;

	init_x = x;
	init_p = prior;
	while (x >= 0)
	{
		if (prior < map->heatarr[y][x] ||
				map->heatarr[y][x] == 0 || map->heatarr[y][x] == -1)
			map->heatarr[y][x] = prior;
		x--;
		prior++;
	}
	prior = init_p;
	x = init_x;
	while (x < map->x)
	{
		if (prior < map->heatarr[y][x] ||
				map->heatarr[y][x] == 0 || map->heatarr[y][x] == -1)
			map->heatarr[y][x] = prior;
		x++;
		prior++;
	}
}

static void	set_priority(t_map *map, int y, int x, int prior)
{
	horizontal_axis(map, y, x, prior);
	vertical_axis(map, y, x, prior);
}

static void	enemy_located(t_map *map, int y, int x, int n)
{
	while (x < map->x)
	{
		if (map->heatarr[y][x] == -2)
		{
			map->count_e++;
			set_priority(map, y, x, 0);
			map->heatarr[y][x] = 1;
			while (x + n < map->x || x - n >= 0 ||
					y + n < map->y || y - n >= 0)
			{
				if (x - n >= 0 && y - n >= 0)
					set_priority(map, y - n, x - n, n);
				if (x + n < map->x && y - n >= 0)
					set_priority(map, y - n, x + n, n);
				if (x - n >= 0 && y + n < map->y)
					set_priority(map, y + n, x - n, n);
				if (x + n < map->x && y + n < map->y)
					set_priority(map, y + n, x + n, n);
				n++;
			}
			n = 1;
		}
		x++;
	}
}

void		heat_map(t_map *map)
{
	int y;
	int x;
	int n;

	y = 0;
	x = 0;
	n = 1;
	map->count_e = 0;
	while (y < map->y)
	{
		enemy_located(map, y, x, n);
		y++;
	}
	if (map->max_e == map->count_e)
		map->game_over = 1;
	map->max_e = map->count_e;
}
