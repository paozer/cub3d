/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:22:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 17:14:48 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"


static void	ft_color_check(t_color *color_ptr)
{
	(color_ptr->red < 0 || color_ptr->red > 255) ?
		print_error(1, &(color_ptr->red)) : 0;
	(color_ptr->green < 0 || color_ptr->green > 255) ?
		print_error(1, &(color_ptr->red)) : 0;
	(color_ptr->blue < 0 || color_ptr->blue > 255) ?
		print_error(1, &(color_ptr->red)) : 0;
}

static void	ft_path_check(t_map *map)
{
	int		i;
	int		fd;
	size_t	len;

	i = 0;
	while (i < 5)
	{
		if ((fd = open(TEXT_P[i], O_RDONLY)) == -1)
			print_error(2, TEXT_P[i]);
		close(fd);
		len = ft_strlen(TEXT_P[i]) - 4;
		if (ft_strncmp(TEXT_P[i] + len, ".xpm", 4) != 0)
			print_error(3, TEXT_P[i]);
		++i;
	}
}

/* check back if spaces in the map are allowed */
/* put set_player function call in parsing files not in check file */

static void	ft_map_check(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		(map->map[i][0] != '1') ? print_error(5, &i) : 1;
		while (map->map[i][j])
		{
			/* should check conditions here (whitespaces) */
			if (!(ft_strchr("012NSEW", map->map[i][j]) || ft_isspace(map->map[i][j])))
				print_error(4, &map->map[i][j]);
			(ft_strchr("NSEW", map->map[i][j])) ? ft_set_player(map, i, j) : 1;
			++j;
		}
		(map->map[i][j - 1] != '1') ? print_error(5, &i) : 1;
		++i;
	}
}

void		ft_parsing_check(t_map *map)
{
	(map->res_ptr->x <= 0 || map->res_ptr->y <= 0) ?
		(print_error(0, (void *)0)) : 1;
	ft_path_check(map);
	ft_color_check(map->floor_ptr);
	ft_color_check(map->ceiling_ptr);
	ft_map_check(map);
}
