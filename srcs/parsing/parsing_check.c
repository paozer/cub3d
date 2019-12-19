/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:22:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 19:56:48 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error(int flag, void *arg)
{
	write(1, "Error\n", 6);
	(flag == 0) ? ft_printf("Resolution is not valid.\n") : 1;
	(flag == 1) ? ft_printf("Color [%d] is not an RGB value.\n",
				*((int *)arg)) : 1;
	(flag == 2) ? ft_printf("File \"%s\" does not exist.\n", arg) : 1;
	(flag == 3) ? ft_printf("Path extension \"%s\" is not valid.\n", arg) : 1;
	(flag == 4) ? ft_printf("Map character \"%c\" is not valid.\n",
				*((char *)arg)) : 1;
	(flag == 5) ? ft_printf("Map is not enclosed by walls in row %d.\n",
				*((int *)arg) + 1) : 1;
	(flag == 6) ? ft_printf("Multiple start positions for player.\n") : 1;
	(flag == 7) ? ft_printf("No start position for player.\n") : 1;
	exit(0);
}

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
		(map->map[i][j] != '1') ? print_error(5, &i) : 1;
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
	(PLAYER->x == 0 && PLAYER->y == 0) ? print_error(7, (void *)0) : 0;
}

void	check_parsing(t_map *map)
{
	(RES->x <= 0 || RES->y <= 0) ?
		(print_error(0, (void *)0)) : 1;
	check_path(map);
	check_map(map);
}
