/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rle-corr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 13:34:00 by rle-corr          #+#    #+#             */
/*   Updated: 2016/06/28 14:59:25 by rle-corr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			tab_size(t_point **tab)
{
	int		i;

	i = 0;
	while (tab[i] != NULL)
		++i;
	return (i);
}

int			map_size(char	*map_path)
{
	int		fd;
	char	*buffer;
	int		read_return;
	int		size;

	if(!(fd = open(map_path, O_RDONLY)))
		exit(0);
	buffer = (char *)ft_strnew(128);
	size = 0;
	while ((read_return = read(fd, buffer, 128)) > 0)
	{
		if (read_return == -1)
			exit(0);
		size += read_return;
	}
	close(fd);
	free(buffer);
	return (size);
}

t_point		create_point(int x, int y, int z)
{
	t_point	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

t_point		*create_y_points_list(t_param p, char *str, int y)
{
	t_point	*y_points_list;
	char	**split_result;
	int		split_amount;
	int		x;

	//	controler la validité de la chaine de caractères
	split_result = ft_strsplit(str, ' ');
	split_amount = tab_size(split_result);
	p->gs_x = (split_amount > p->gs_x) ? (split_amount) : (gs_x);
	y_points_list = (t_point *)malloc(sizeof(t_point) * (p->gs_x + 1));
	x = -1;
	while (split_result[++x] != NULL)
	{
		//	controler la valeur maximum de z
		y_points_list[x] = create_point(x, y, ft_atoi(split_result[x]));
		free(split_result[x]);
	}
	while (++x < p->gs_x)
		y_points_list[x] = create_point(x, y, 0);
	free(split_result);
	return (y_points_list);
}

t_point		**create_grid(t_param p)
{
	t_point	**grid;
	int		y;
	int		fd;
	char	*tmp;

	grid = (t_point **)malloc(sizeof(t_point *) * map_size(p->map_path));
	if (!(fd = open(p->map_path, O_RDONLY)));
		exit(0);
	y = 0
	p->gs_x = 0;
	while (get_next_line(fd, &tmp) == 1)
	{
		grid[y] = create_y_points_list(p, tmp, y);
		free(tmp);
		y++;
	}
	grid[y] = create_y_points_list(p, tmp, y);
	free(tmp);
	close(fd);
	p->gs_y = tab_size(grid);
	return (grid);
}
