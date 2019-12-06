/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 19:29:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/06 12:59:41 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

static void	ft_set_resolution(char *line, t_map *map)
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

static char	*ft_set_paths(char *line)
{
	int	i;
	char *str;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	str = ft_strdup(line + i);
	return (str);
}

static void ft_set_colour(char *line, t_map *map, int flag)
{
	int i;
	t_colour *tmp;

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

int		ft_parsing(char *params, t_map **map)
{
	int		fd;
	int		ret;
	char	*line;

	*map = ft_init_map();
	if ((fd = open(params, O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		while (line[i] && ft_isspace(line[i]) == 1)
				++i;
		(line[i] == 'R') ? ft_set_resolution(line + i + 1, *map) : 1;
		(line[i] == 'N' && line[i + 1] == 'O') ? (*map->text_ptr->north = ft_set_paths(line + 2)) : 1;
		(line[i] == 'S' && line[i + 1] == 'O') ? (*map->text_ptr->south = ft_set_paths(line + 2)) : 1;
		(line[i] == 'W' && line[i + 1] == 'E') ? (*map->text_ptr->west = ft_set_paths(line + 2)) : 1;
		(line[i] == 'E' && line[i + 1] == 'A') ? (*map->text_ptr->east = ft_set_paths(line + 2)) : 1;
		(line[i] == 'S' && line[i + 1] == ' ') ? (*map->text_ptr->sprite = ft_set_paths(line + 2)) : 1;
		(line[i] == 'F' && line[i + 1] == ' ') ? ft_set_colour(line + 2, *map, 0) : 1;
		(line[i] == 'C' && line[i + 1] == ' ') ? ft_set_colour(line + 2, *map, 1) : 1;
		free(line);
	}
}
