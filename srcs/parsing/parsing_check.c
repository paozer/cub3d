/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:22:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 19:17:17 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_color(int r, int g, int b)
{
	(r < 0 || r > 255) ? print_error(1, &(r)) : 0;
	(g < 0 || g > 255) ? print_error(1, &(g)) : 0;
	(b < 0 || b > 255) ? print_error(1, &(b)) : 0;
}

void	check_path(t_map *map)
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

/* put set_player function call in parsing files not in check file */

void	check_map(t_map *map)
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
			if (!(ft_strchr("012NSEW", map->map[i][j]) ||
						ft_isspace(map->map[i][j])))
				print_error(4, &map->map[i][j]);
			(ft_strchr("NSEW", map->map[i][j])) ? set_player(map, i, j) : 1;
			++j;
		}
		(map->map[i][j - 1] != '1') ? print_error(5, &i) : 1;
		++i;
	}
}

void	check_parsing(t_map *map)
{
	(map->res_ptr->x <= 0 || map->res_ptr->y <= 0) ?
		(print_error(0, (void *)0)) : 1;
	check_path(map);
	check_map(map);
}
