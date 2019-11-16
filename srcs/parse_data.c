/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:13:10 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/12 02:33:57 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	game_overheat(t_map *map)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < map->y)
	{
		while (x < map->x)
		{
			map->heatarr[y][x] = 1;
			x++;
		}
		x = 0;
		y++;
	}
}

int		choose_algo(t_draw *draw, t_map *map)
{
	draw->ly = 0;
	draw->lx = 0;
	draw->newmap = 1;
	while (draw->ly < map->y)
	{
		while (draw->lx < map->x)
		{
			if (map->arr[draw->ly][draw->lx] == draw->player)
			{
				if (draw->ly < (map->y / 2) && draw->lx < (map->x / 2))
					return (1);
				else if (draw->ly > (map->y / 2) && draw->lx > (map->x / 2))
					return (2);
				else if (draw->ly < (map->y / 2) && draw->lx > (map->x / 2))
					return (3);
				else if (draw->ly > (map->y / 2) && draw->lx < (map->x / 2))
					return (4);
			}
			draw->lx++;
		}
		draw->lx = 0;
		draw->ly++;
	}
	return (1);
}

void	get_piece(char *line, t_map *map, t_piece *piece, t_draw *draw)
{
	while (!(*line >= '0' && *line <= '9'))
		line++;
	piece->y = ft_atoi(line);
	while (*line != ' ')
		line++;
	piece->x = ft_atoi(line);
	if (!(piece->arr = (char**)malloc(sizeof(char*) * piece->y)))
		exit(0);
	create_piece(line, piece, draw);
	if (!draw->newmap)
		draw->algo = choose_algo(draw, map);
	if (draw->algo == 1)
		put_piece_algo1(map, piece, draw, 1);
	else if (draw->algo == 2)
		put_piece_algo2(map, piece, draw, 1);
	else if (draw->algo == 3)
		put_piece_algo3(map, piece, draw, 1);
	else if (draw->algo == 4)
		put_piece_algo4(map, piece, draw, 1);
}

void	get_letter(char *line, t_draw *draw)
{
	if (ft_strstr(line, "p1"))
		draw->player = 'O';
	else
		draw->player = 'X';
	draw->enemy = draw->player == 'O' ? 'X' : 'O';
}

void	get_map(char *line, t_map *map, t_draw *draw)
{
	while (!(*line >= '0' && *line <= '9'))
		line++;
	map->y = ft_atoi(line);
	while (*line != ' ')
		line++;
	map->x = ft_atoi(line);
	get_next_line(0, &line);
	if (!(map->arr = (char**)malloc(sizeof(char*) * map->y)))
		exit(0);
	if (!(map->heatarr = (int**)malloc(sizeof(int*) * map->y)))
		exit(0);
	create_map(line, map, draw);
	if (map->game_over)
		game_overheat(map);
	else
		heat_map(map);
}
