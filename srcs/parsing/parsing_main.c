/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 19:29:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/18 12:54:51 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

static void		ft_set_resolution(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	map->res_ptr->x = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	while (line[i] && ft_isspace(line[i]))
		++i;
	map->res_ptr->y = ft_atoi(line + i);
}

static char		*ft_set_paths(char *line)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	str = ft_strdup(line + i);
	return (str);
}

static void		ft_set_color(char *line, t_map *map, int flag)
{
	int		i;
	t_color	*tmp;

	i = 0;
	tmp = (flag == 0) ? map->floor_ptr : map->ceiling_ptr;
	while (line[i] && ft_isspace(line[i]))
		++i;
	tmp->red = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	(line[i] == ',') ? ++i : 1;
	while (line[i] && ft_isspace(line[i]))
		++i;
	tmp->green = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	(line[i] == ',') ? ++i : 1;
	while (line[i] && ft_isspace(line[i]))
		++i;
	tmp->blue = ft_atoi(line + i);
	tmp->clr = (tmp->red << 16) | (tmp->green << 8) | (tmp->blue);
}

void			ft_set_player(t_map *map, int x, int y)
{
	if (PLAYER->set_flag == 1)
		print_error(6, (void *)0);
	PLAYER->set_flag = 1;
	PLAYER->x = x + .5;
	PLAYER->y = y + .5;
	if (map->map[x][y] == 'N' || map->map[x][y] == 'S')
	{
		PLAYER->dir_y = 0;
		PLAYER->dir_x = (map->map[x][y] == 'N') ? -1 : 1;
		SCREEN->plane_x = 0;
		SCREEN->plane_y = (map->map[x][y] == 'N') ? .66 : -.66;
	}
	if (map->map[x][y] == 'W' || map->map[x][y] == 'E')
	{
		PLAYER->dir_x = 0;
		PLAYER->dir_y = (map->map[x][y] == 'W') ? -1 : 1;
		SCREEN->plane_y = 0;
		SCREEN->plane_x = (map->map[x][y] == 'W') ? -.66 : .66;
	}
}

t_map			*ft_parsing(char *params)
{
	int		i;
	int		fd;
	char	*line;
	t_map	*map;

	i = 0;
	fd = 0;
	line = NULL;
	/* basic error checking */
	if ((fd = open(params, O_RDONLY)) == -1)
		print_error(2, params);
	(ft_strncmp(params + ft_strlen(params) - 4, ".cub", 4) != 0) ?
		print_error(3, params) : 1;
	/* end */
	map = ft_init_map();
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i] && ft_isspace(line[i]) == 1)
			++i;
		(line[i] == 'R') ? ft_set_resolution(line + i + 1, map) : 1;
		(line[i] == 'N' && line[i + 1] == 'O') ?
				(TEXT_P[0] = ft_set_paths(line + 2)) : 0;
		(line[i] == 'S' && line[i + 1] == 'O') ?
				(TEXT_P[1] = ft_set_paths(line + 2)) : 0;
		(line[i] == 'W' && line[i + 1] == 'E') ?
				(TEXT_P[2] = ft_set_paths(line + 2)) : 0;
		(line[i] == 'E' && line[i + 1] == 'A') ?
				(TEXT_P[3] = ft_set_paths(line + 2)) : 0;
		(line[i] == 'S' && line[i + 1] != 'O') ?
				(TEXT_P[4] = ft_set_paths(line + 1)) : 0;
		(line[i] == 'F') ? ft_set_color(line + 2, map, 0) : 0;
		(line[i] == 'C') ? ft_set_color(line + 2, map, 1) : 0;
		if (ft_isdigit(line[i]))
			break ;
		free(line);
	}
	ft_set_map(map, fd, &line);
	ft_parsing_check(map);
	if (close(fd) == -1)
		return (NULL);
	return (map);
}
