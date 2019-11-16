/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:32:50 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/11 23:44:02 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	print_coordinates(t_map *map, t_piece *piece, int y, int x)
{
	char *s_y;
	char *s_x;

	s_y = ft_itoa(y);
	s_x = ft_itoa(x);
	ft_putstr(s_y);
	ft_putchar(' ');
	ft_putstr(s_x);
	ft_putchar('\n');
	free(s_y);
	free(s_x);
	free_piece(piece);
	free_map(map);
}

int		overlap_check(t_map *map, t_piece *piece, t_draw *draw)
{
	while (draw->lx < piece->x)
	{
		if (draw->y + draw->ly < map->y && draw->x + draw->lx < map->x)
		{
			if (map->arr[draw->y + draw->ly][draw->x + draw->lx] == draw->enemy
					&& piece->arr[draw->ly][draw->lx] == draw->player)
				return (0);
			else if (piece->arr[draw->ly][draw->lx] == draw->player &&
					piece->arr[draw->ly][draw->lx] ==
					map->arr[draw->y + draw->ly][draw->x + draw->lx])
				draw->overlap++;
			if (draw->overlap > 1)
				return (0);
		}
		else
			return (0);
		draw->lx++;
	}
	return (1);
}

int		is_valid(t_map *map, t_piece *piece, t_draw *draw)
{
	draw->ly = 0;
	draw->lx = 0;
	draw->overlap = 0;
	while (draw->ly < piece->y)
	{
		if (!(overlap_check(map, piece, draw)))
			return (0);
		draw->lx = 0;
		draw->ly++;
	}
	if (draw->overlap == 1)
		return (1);
	return (0);
}
