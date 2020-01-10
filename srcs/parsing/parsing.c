/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 19:29:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 14:44:05 by paozer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_resolution(char *line, t_map *map)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	map->re->x = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	while (line[i] && ft_isspace(line[i]))
		++i;
	map->re->y = ft_atoi(line + i);
	++map->config_flag;
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
	(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) ?
		map->flag_clr = 1 : 0;
	(flag == 1) ? (*map->cc = (r << 16) | (g << 8) | (b)) :
		(*map->fc = (r << 16) | (g << 8) | (b));
	++map->config_flag;
}

void			set_player(t_map *map, int x, int y)
{
	map->p->set_flag++;
	map->p->x = x + .5;
	map->p->y = y + .5;
	if (map->map[x][y] == 'N' || map->map[x][y] == 'S')
	{
		map->p->dir_y = 0;
		map->p->dir_x = (map->map[x][y] == 'N') ? -1 : 1;
		map->s->plane_x = 0;
		map->s->plane_y = (map->map[x][y] == 'N') ? .66 : -.66;
	}
	if (map->map[x][y] == 'W' || map->map[x][y] == 'E')
	{
		map->p->dir_x = 0;
		map->p->dir_y = (map->map[x][y] == 'W') ? -1 : 1;
		map->s->plane_y = 0;
		map->s->plane_x = (map->map[x][y] == 'W') ? -.66 : .66;
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
			(map->tp[0] = set_paths(line + 2, map)) : 0;
		(line[i] == 'S' && line[i + 1] == 'O') ?
			(map->tp[1] = set_paths(line + 2, map)) : 0;
		(line[i] == 'W' && line[i + 1] == 'E') ?
			(map->tp[2] = set_paths(line + 2, map)) : 0;
		(line[i] == 'E' && line[i + 1] == 'A') ?
			(map->tp[3] = set_paths(line + 2, map)) : 0;
		(line[i] == 'S' && line[i + 1] != 'O') ?
			(map->tp[4] = set_paths(line + 1, map)) : 0;
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
