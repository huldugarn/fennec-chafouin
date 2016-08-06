/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_2_auxiliary_input_parsing.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/04 15:57:56 by rle-corr          #+#    #+#             */
/*   Updated: 2016/08/06 16:48:19 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_0_header.h"

t_p			**create_grid(t_e *e)
{
	t_p		**grid;
	int		y;
	int		file_descriptor;
	char	*buffer;

	grid = (t_p **)malloc(sizeof(t_p *) * map_size(e->map_path));
	if (!(file_descriptor = open(e->map_path, O_RDONLY)))
		exit(0);
	y = 0;
	e->gs_x = 0;
	while (get_next_line(file_descriptor, &buffer))
	{
		grid[y] = create_y_points_list(e, buffer, y);
		free(buffer);
		++y;
	}
	grid[y] = create_y_points_list(e, buffer, y);
	free(buffer);
	close(file_descriptor);
	e->gs_y = tab_size(grid);
	return (grid);
}

t_p			*create_y_points_list(t_e *e, char *buffer, int y)
{
	t_p		*y_points_list;
	char	**split_result;
	int		split_amount;
	int		x;
	int		z;

	//	controler la validité de la chaine de caractères
	split_result = ft_strsplit(buffer, ' ');
	split_amount = tab_size((t_p **)split_result);
	e->gs_x = (split_amount > e->gs_x) ? (split_amount) : (e->gs_x);
	y_points_list = (t_p *)malloc(sizeof(t_p) * (e->gs_x + 1));
	x = -1;
	while (split_result[++x] != NULL)
	{
		z = ft_atoi(split_result[x]);
		e->z_max = z > e->z_max ? z : e->z_max;
		y_points_list[x] = create_point(x, y, z);
		free(split_result[x]);
	}
	while (++x < e->gs_x)
	{
		y_points_list[x] = create_point(x, y, 0);
	}
	free(split_result);
	return (y_points_list);
}

t_p			create_point(int x, int y, int z)
{
	t_p		point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

int			map_size(char *map_path)
{
	int		file_descriptor;
	char	*buffer;
	int		read_return;
	int		size;

	if (!(file_descriptor = open(map_path, O_RDONLY)))
		exit(0);
	buffer = (char *)ft_strnew(128);
	size = 0;
	while ((read_return = read(file_descriptor, buffer, 128)) > 0)
	{
		if (read_return == -1)
			exit(0);
		size += read_return;
	}
	close(file_descriptor);
	free(buffer);
	return (size);
}

int			tab_size(t_p **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		++i;
	return (i);
}
