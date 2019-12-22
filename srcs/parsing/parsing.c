/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 19:29:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 04:44:23 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

static void		set_resolution(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	RES->x = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	while (line[i] && ft_isspace(line[i]))
		++i;
	RES->y = ft_atoi(line + i);
}

static void		set_color(char *line, t_map *map, int flag)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	r = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	(line[i] == ',') ? ++i : 1;
	while (line[i] && ft_isspace(line[i]))
		++i;
	g = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	(line[i] == ',') ? ++i : 1;
	while (line[i] && ft_isspace(line[i]))
		++i;
	b = ft_atoi(line + i);
	check_color(r, g, b, map);
	(flag == 1) ? (*map->cei_clr = (r << 16) | (g << 8) | (b)) :
		(*map->flo_clr = (r << 16) | (g << 8) | (b));
}

void			set_player(t_map *map, int x, int y)
{
	PLAYER->set_flag++;
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

char			*gnl_file(t_map *map, int fd, int i)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i] && ft_isspace(line[i]) == 1)
			++i;
		(line[i] == 'R') ? set_resolution(line + i + 1, map) : 1;
		(line[i] == 'N' && line[i + 1] == 'O') ?
			(TEXT_P[0] = set_paths(line + 2)) : 0;
		(line[i] == 'S' && line[i + 1] == 'O') ?
			(TEXT_P[1] = set_paths(line + 2)) : 0;
		(line[i] == 'W' && line[i + 1] == 'E') ?
			(TEXT_P[2] = set_paths(line + 2)) : 0;
		(line[i] == 'E' && line[i + 1] == 'A') ?
			(TEXT_P[3] = set_paths(line + 2)) : 0;
		(line[i] == 'S' && line[i + 1] != 'O') ?
			(TEXT_P[4] = set_paths(line + 1)) : 0;
		(line[i] == 'F') ? set_color(line + 2, map, 0) : 0;
		(line[i] == 'C') ? set_color(line + 2, map, 1) : 0;
		if (ft_isdigit(line[i]))
			return (line);
		free(line);
	}
	return (NULL);
}

t_map			*parsing(char *params)
{
	int		i;
	int		fd;
	char	*line;
	t_map	*map;

	i = 0;
	line = NULL;
	map = init_map();
	if ((fd = open(params, O_RDONLY)) == -1)
		print_error(2, params, map, 1);
	(ft_strncmp(params + ft_strlen(params) - 4, ".cub", 4) != 0) ?
		print_error(3, params, map, 1) : 1;
	line = gnl_file(map, fd, i);
	set_map(map, fd, line);
	check_parsing(map);
	close(fd);
	return (map);
}
