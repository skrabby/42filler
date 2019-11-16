/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:13:12 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/15 08:34:12 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	free_str(t_map *map, t_draw *draw, t_piece *piece)
{
	free(map);
	free(draw);
	free(piece);
}

static void	set_var(t_draw *draw, t_map *map)
{
	draw->player = '\0';
	draw->newmap = 0;
	map->game_over = 0;
	map->max_e = 0;
}

int			main(void)
{
	t_map	*map;
	t_piece *piece;
	t_draw	*draw;
	char	*line;

	if (!(map = (t_map*)malloc(sizeof(t_map))) ||
		!(piece = (t_piece*)malloc(sizeof(t_piece))) ||
		!(draw = (t_draw*)malloc(sizeof(t_draw))))
		exit(0);
	set_var(draw, map);
	while (1)
	{
		get_next_line(0, &line);
		if (line[0] == '$' && draw->player == '\0')
			get_letter(line, draw);
		else if (line[0] == 'P' && line[1] == 'l')
			get_map(line, map, draw);
		else if (line[0] == 'P' && line[1] == 'i')
			get_piece(line, map, piece, draw);
		free(line);
		if (line[0] == '\0')
			break ;
	}
	free_str(map, draw, piece);
	return (0);
}
