/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 21:31:02 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/11 21:38:28 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	put_piece_algo4(t_map *map, t_piece *piece, t_draw *draw, int prior)
{
	draw->y = 0;
	draw->x = map->x - 1;
	draw->end = 0;
	while (draw->y < map->y)
	{
		while (draw->x >= 0)
		{
			if (map->heatarr[draw->y][draw->x] == prior)
			{
				draw->end++;
				if (is_valid(map, piece, draw))
				{
					print_coordinates(map, piece, draw->y, draw->x);
					return ;
				}
			}
			draw->x--;
		}
		draw->x = map->x - 1;
		draw->y++;
	}
	if (!draw->end)
		print_coordinates(map, piece, 0, 0);
	else
		put_piece_algo2(map, piece, draw, prior + 1);
}

void	put_piece_algo3(t_map *map, t_piece *piece, t_draw *draw, int prior)
{
	draw->y = map->y - 1;
	draw->x = 0;
	draw->end = 0;
	while (draw->y >= 0)
	{
		while (draw->x < map->x)
		{
			if (map->heatarr[draw->y][draw->x] == prior)
			{
				draw->end++;
				if (is_valid(map, piece, draw))
				{
					print_coordinates(map, piece, draw->y, draw->x);
					return ;
				}
			}
			draw->x++;
		}
		draw->x = 0;
		draw->y--;
	}
	if (!draw->end)
		print_coordinates(map, piece, 0, 0);
	else
		put_piece_algo1(map, piece, draw, prior + 1);
}

void	put_piece_algo2(t_map *map, t_piece *piece, t_draw *draw, int prior)
{
	draw->y = 0;
	draw->x = 0;
	draw->end = 0;
	while (draw->y < map->y)
	{
		while (draw->x < map->x)
		{
			if (map->heatarr[draw->y][draw->x] == prior)
			{
				draw->end++;
				if (is_valid(map, piece, draw))
				{
					print_coordinates(map, piece, draw->y, draw->x);
					return ;
				}
			}
			draw->x++;
		}
		draw->x = 0;
		draw->y++;
	}
	if (!draw->end)
		print_coordinates(map, piece, 0, 0);
	else
		put_piece_algo2(map, piece, draw, prior + 1);
}

void	put_piece_algo1(t_map *map, t_piece *piece, t_draw *draw, int prior)
{
	draw->y = map->y - 1;
	draw->x = map->x - 1;
	draw->end = 0;
	while (draw->y >= 0)
	{
		while (draw->x >= 0)
		{
			if (map->heatarr[draw->y][draw->x] == prior)
			{
				draw->end++;
				if (is_valid(map, piece, draw))
				{
					print_coordinates(map, piece, draw->y, draw->x);
					return ;
				}
			}
			draw->x--;
		}
		draw->x = map->x - 1;
		draw->y--;
	}
	if (!draw->end)
		print_coordinates(map, piece, 0, 0);
	else
		put_piece_algo1(map, piece, draw, prior + 1);
}
