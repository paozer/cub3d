/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:22:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 03:55:41 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"


static void	ft_color_check(t_color *color_ptr)
{
	(color_ptr->red < 0 || color_ptr->red > 255) ?
		ft_print_error(1, &(color_ptr->red)) : 0;
	(color_ptr->green < 0 || color_ptr->green > 255) ?
		ft_print_error(1, &(color_ptr->red)) : 0;
	(color_ptr->blue < 0 || color_ptr->blue > 255) ?
		ft_print_error(1, &(color_ptr->red)) : 0;
}

static void	ft_path_check(char *path)
{
	int		fd;
	size_t	len;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_print_error(2, path);
	close(fd);
	len = ft_strlen(path) - 4;
	if (ft_strncmp(path + len, ".xpm", 4) != 0)
		ft_print_error(3, path);
}

/* check back if spaces in the map are allowed */

static void	ft_map_check(t_map **map)
{
	int i;
	int j;
	char **map_ptr;

	i = 0;
	map_ptr = (*map)->map;
	while (map_ptr[i])
	{
		j = 0;
		(map_ptr[i][0] != '1') ? ft_print_error(5, &i) : 1;
		while (map_ptr[i][j])
		{
			if (!(ft_strchr("012NSEW", map_ptr[i][j]) || ft_isspace(map_ptr[i][j])))
				ft_print_error(4, &map_ptr[i][j]);
			(ft_strchr("NSEW", map_ptr[i][j])) ? ft_init_player(map, j, i) : 1;
			++j;
		}
		(map_ptr[i][j - 1] != '1') ? ft_print_error(5, &i) : 1;
		++i;
	}
}

void		ft_parsing_check(t_map **map)
{
	((*map)->res_ptr->x <= 0 || (*map)->res_ptr->y <= 0) ?
		(ft_print_error(0, (void *)0)) : 1;
	ft_path_check((*map)->text_ptr->north);
	ft_path_check((*map)->text_ptr->south);
	ft_path_check((*map)->text_ptr->west);
	ft_path_check((*map)->text_ptr->east);
	ft_path_check((*map)->text_ptr->sprite);
	ft_color_check((*map)->floor_ptr);
	ft_color_check((*map)->ceiling_ptr);
	ft_map_check(map);
}
