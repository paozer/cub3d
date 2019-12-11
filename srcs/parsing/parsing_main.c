/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_main.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 19:29:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 17:50:17 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

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
}

int				ft_parsing(char *params, t_map **map)
{
	int		i;
	int		fd;
	char	*line;

	if ((fd = open(params, O_RDONLY)) == -1)
		ft_print_error(2, params);
	(ft_strncmp(params + ft_strlen(params) - 4, ".cub", 4) != 0) ?
		ft_print_error(3, params) : 1;
	*map = ft_init_map();
	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i] && ft_isspace(line[i]) == 1)
			++i;
		(line[i] == 'R') ? ft_set_resolution(line + i + 1, *map) : 1;
		(line[i] == 'N' && line[i + 1] == 'O') ? ((*map)->text_ptr->north = ft_set_paths(line + 2)) : 0;
		(line[i] == 'S' && line[i + 1] == 'O') ? ((*map)->text_ptr->south = ft_set_paths(line + 2)) : 0;
		(line[i] == 'W' && line[i + 1] == 'E') ? ((*map)->text_ptr->west = ft_set_paths(line + 2)) : 0;
		(line[i] == 'E' && line[i + 1] == 'A') ? ((*map)->text_ptr->east = ft_set_paths(line + 2)) : 0;
		(line[i] == 'S' && line[i + 1] != 'O') ? ((*map)->text_ptr->sprite = ft_set_paths(line + 1)) : 0;
		(line[i] == 'F') ? ft_set_color(line + 2, *map, 0) : 0;
		(line[i] == 'C') ? ft_set_color(line + 2, *map, 1) : 0;
		if (ft_isdigit(line[i]))
			break ;
		free(line);
	}
	ft_set_map(map, fd, &line);
	ft_parsing_check(map);
	if (close(fd) == -1)
		return (-1);
	return (0);
}
