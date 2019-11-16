/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 02:28:58 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/11 03:08:04 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	create_piece(char *line, t_piece *piece, t_draw *draw)
{
	int y;
	int x;

	y = 0;
	x = 0;
	while (y < piece->y)
	{
		get_next_line(0, &line);
		if (!(piece->arr[y] = (char*)malloc(sizeof(char) * piece->x)))
			exit(0);
		while (x < piece->x)
		{
			if (line[x] == '.')
				piece->arr[y][x] = line[x];
			else if (line[x] == '*')
				piece->arr[y][x] = draw->player;
			x++;
		}
		x = 0;
		y++;
		free(line);
	}
	y = 0;
}

void	free_piece(t_piece *piece)
{
	int y;

	y = 0;
	while (y < piece->y)
	{
		free(piece->arr[y]);
		y++;
	}
	free(piece->arr);
}
