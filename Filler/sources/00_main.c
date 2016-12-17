/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:55:00 by rle-corr          #+#    #+#             */
/*   Updated: 2016/11/22 12:57:49 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		filler_init(t_flr *fs)
{
	fs->turn = 0;
	fs->p_nb = 0;
	fs->pawn = 0;
//	fs->mapX = 0;
//	fs->mapY = 0;
	(fs->posO).x = 0;
	(fs->posO).y = 0;
	(fs->posX).x = 0;
	(fs->posX).y = 0;
	fs->Oscr = 0;
	fs->Xscr = 0;
}

void		filler_structure_print(t_flr fs)
{
	ft_putstr("	p_nb :	");	ft_putnbr(fs.p_nb);
	ft_putstr("	pawn :	");	ft_putchar(fs.pawn);
	ft_putstr("	turn :	");	ft_putnbr(fs.turn);
	ft_putendl(";");
//	ft_putstr("	mapX :	");	ft_putnbr(fs.mapX);
//	ft_putstr("	mapY :	");	ft_putnbr(fs.mapY);
//	ft_putendl(";");
	ft_putstr("	pO_x :	");	ft_putnbr((fs.posO).x);
	ft_putstr("	pO_y :	");	ft_putnbr((fs.posO).y);
	ft_putendl(";");
	ft_putstr("	pX_x :	");	ft_putnbr((fs.posX).x);
	ft_putstr("	pX_y :	");	ft_putnbr((fs.posX).y);
	ft_putendl(";");
}

void		filler_grid_print(t_grd *grid)
{
	int		i;

	i = 0;
	while (i <= grid->h)
	{
		ft_putendl(grid->data[i]);
		++i;
	}
}

int			filler_player_number(char *s, t_flr *fs)
{
	char	*f;
	int		i;

	f = "$$$ exec p_ : rle-corr";
	i = 0;
	while (s[i] != '\0')
	{
		if (i == 10)
		{
			if (s[i] == '1' || s[i] == '2')
			{
				fs->p_nb = (s[i] == '1') ? 1 : 2;
				fs->pawn = (s[i] == '1') ? 'O' : 'X';
			}
			else
				return (1);
			++i;
		}
		else if (s[i] != f[i])
			return (1);
		++i;
	}
	return (0);
}

void		filler_getboard(char *line, t_grd *board)
{
	t_coords	coords;
	int			i;

	coords.x = 0;
	coords.y = 0;
	i = 8;

	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		coords.x = coords.x * 10 + (line[i++] - '0');
	while (ft_isdigit(line[++i]))
		coords.y = coords.y * 10 + (line[i] - '0');
	board->h = coords.x + 1; // pourquoi + 1 ?
	board->w = coords.y + 1; // pourquoi + 1 ?
	board->data = (char **)ft_memalloc(sizeof(char *) * (coords.x + 2)); // pourquoi coords + 2 ?
	board->data[coords.x + 1] = NULL;
	get_next_line(1, &line);
	free(&line);
	i = -1;
	while (++i <= coords.x && get_next_line(1, &line) != 0)
	{
		board->data[i] = ft_strdup(&line[4]);
		free(&line);
	}
}

void		filler_getpiece(char *line, t_grd *piece)
{
	t_coords	coords;
	int			i;

	coords.x = 0;
	coords.y = 0;
	i = 6;

	while (!ft_isdigit(line[i]))
		++i;
	while (ft_isdigit(line[i]))
		coords.x = coords.x * 10 + (line[i++] - '0');
	while (ft_isdigit(line[++i]))
		coords.y = coords.y * 10 + (line[i] - '0');
	piece->h = coords.x;
	piece->w = coords.y;
	piece->data = (char **)ft_memalloc(sizeof(char *) * (coords.x + 1)); // pourquoi coords + 1 ?
	piece->data[coords.x] = NULL;
	get_next_line(1, &line);
	free(&line);
	i = -1;
	while (++i <= coords.x && get_next_line(1, &line) != 0)
	{
		piece->data[i] = ft_strdup(line);
		free(&line);
	}
}

int			filler_input(t_flr *fsp, t_grd *board, t_grd *piece)
{
	char	*buffer;

	while (get_next_line(1, &buffer))
	{
		if (fsp->turn == 0 && fsp->p_nb == 0)
		{

			if (filler_player_number(buffer, fsp))
			{
				perror("Unexpected player number or name");
				return (0);
			}
		}
		else if (ft_strncmp(buffer, "Plateau", 7) == 0)
		{
				filler_getboard(buffer, board);
		}
		else if (ft_strncmp(buffer, "Piece", 5) == 0)
		{
			filler_getpiece(buffer, piece);
			return (1);
		}
	
	}
	++(fsp->turn);
	return (0);
}

int			main(void)
{
	t_flr	filler_structure;
	t_grd	*board;
	t_grd	*piece;

	filler_init(&filler_structure);
	board = (t_grd *)ft_memalloc(sizeof(*board));
	piece = (t_grd *)ft_memalloc(sizeof(*piece));
	filler_structure_print(filler_structure);//debug
	filler_input(&filler_structure, board, piece);
	filler_grid_print(board);//debug
	filler_structure_print(filler_structure);//debug
//	filler_resolve(filler_structure);
//	filler_output(filler_structure);
	return (0);
}
