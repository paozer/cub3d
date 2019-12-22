/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:22:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 10:40:47 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_color(int r, int g, int b, t_map *map)
{
	(r < 0 || r > 255) ? print_error(1, &(r), map, 1) : 0;
	(g < 0 || g > 255) ? print_error(1, &(g), map, 1) : 0;
	(b < 0 || b > 255) ? print_error(1, &(b), map, 1) : 0;
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
			print_error(2, TEXT_P[i], map, 1);
		close(fd);
		len = ft_strlen(TEXT_P[i]) - 4;
		if (ft_strncmp(TEXT_P[i] + len, ".xpm", 4) != 0)
			print_error(3, TEXT_P[i], map, 1);
		++i;
	}
}

void	check_map(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (map->map[i])
	{
		j = 0;
		(map->map[i][j] != '1') ? print_error(5, &i, map, 1) : 1;
		while (map->map[i][j])
		{
			if (!(ft_strchr("012NSEW", map->map[i][j]) ||
						ft_isspace(map->map[i][j])))
				print_error(4, &map->map[i][j], map, 1);
			(ft_strchr("NSEW", map->map[i][j])) ? set_player(map, i, j) : 1;
			++j;
		}
		(map->map[i][j - 1] != '1') ? print_error(5, &i, map, 1) : 1;
		++i;
	}
	(PLAYER->x == 0 && PLAYER->y == 0) ? print_error(7, (void *)0, map, 1) : 0;
}

void	check_parsing(t_map *map)
{
	(RES->x <= 0 || RES->y <= 0) ? (print_error(0, (void *)0, map, 1)) : 1;
	(RES->x >= 5120) ? RES->x = 5120 / 2 : 0;
	(RES->y >= 2880) ? RES->y = 1395 : 0;
	(map->config_flag != 8) ? print_error(9, (void *)0, map, 1) : 0;
	check_path(map);
	check_map(map);
	(PLAYER->set_flag != 1) ? print_error(6, (void *)0, map, 1) : 0;
}
