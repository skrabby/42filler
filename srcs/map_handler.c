/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:13:16 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/12 04:18:09 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		free_map(t_map *map)
{
	int y;

	y = 0;
	while (y < map->y)
	{
		free(map->arr[y]);
		free(map->heatarr[y]);
		y++;
	}
	free(map->arr);
	free(map->heatarr);
}

static void	adapt_map(char *line, t_map *map, t_draw *draw)
{
	while (map->lx < map->x)
	{
		if (line[map->lx] == 'o' || line[map->lx] == 'x')
			map->arr[map->ly][map->lx] = ft_toupper(line[map->lx]);
		else
			map->arr[map->ly][map->lx] = line[map->lx];
		if (line[map->lx] == '.')
			map->heatarr[map->ly][map->lx] = 0;
		else if (ft_toupper(line[map->lx]) == draw->player)
			map->heatarr[map->ly][map->lx] = -1;
		else if (ft_toupper(line[map->lx]) == draw->enemy)
			map->heatarr[map->ly][map->lx] = -2;
		map->lx++;
	}
}

void		create_map(char *line, t_map *map, t_draw *draw)
{
	char	*begin;

	map->ly = 0;
	map->lx = 0;
	free(line);
	while (map->ly < map->y)
	{
		if (!(map->heatarr[map->ly] = (int*)malloc(sizeof(int) * map->x)))
			exit(0);
		if (!(map->arr[map->ly] = (char*)malloc(sizeof(char) * map->x + 1)))
			exit(0);
		get_next_line(0, &line);
		begin = line;
		while (*line != ' ')
			line++;
		line++;
		adapt_map(line, map, draw);
		free(begin);
		map->arr[map->ly][map->x] = '\0';
		map->lx = 0;
		map->ly++;
	}
}
