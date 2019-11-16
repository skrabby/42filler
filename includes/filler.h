/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skrabby <skrabby@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 03:13:08 by skrabby           #+#    #+#             */
/*   Updated: 2019/11/12 04:17:58 by skrabby          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef struct	s_map
{
	int			y;
	int			x;
	int			ly;
	int			lx;
	int			count_e;
	int			max_e;
	int			game_over;
	int			**heatarr;
	char		**arr;
}				t_map;

typedef struct	s_draw
{
	char		player;
	char		enemy;
	int			newmap;
	int			algo;
	int			overlap;
	int			ly;
	int			lx;
	int			end;
	int			y;
	int			x;

}				t_draw;

typedef struct	s_piece
{
	int			y;
	int			x;
	char		**arr;
}				t_piece;

void			get_letter(char *line, t_draw *draw);
void			get_piece(char *line, t_map *map, t_piece *piece, t_draw *draw);
void			get_map(char *line, t_map *map, t_draw *draw);
void			create_map(char *line, t_map *map, t_draw *draw);
void			free_map(t_map *map);
void			create_piece(char *line, t_piece *piece, t_draw *draw);
void			free_piece(t_piece *piece);
void			put_piece_algo1(t_map *map, t_piece *piece, t_draw *draw,
				int prior);
void			put_piece_algo2(t_map *map, t_piece *piece, t_draw *draw,
				int prior);
void			put_piece_algo3(t_map *map, t_piece *piece, t_draw *draw,
				int prior);
void			put_piece_algo4(t_map *map, t_piece *piece, t_draw *draw,
				int prior);
int				is_valid(t_map *map, t_piece *piece, t_draw *draw);
int				overlap_check(t_map *map, t_piece *piece, t_draw *draw);
void			print_coordinates(t_map *map, t_piece *piece, int y, int x);
void			heat_map(t_map *map);
void			game_overheat(t_map *map);
#endif
