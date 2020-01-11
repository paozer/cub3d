/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   map.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 20:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 21:02:08 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static char	**ft_realloc(char **str, int size, int len)
{
	int		i;
	char	**new_str;

	i = 0;
	if (!(new_str = malloc(sizeof(char*) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(new_str[i] = malloc(sizeof(**new_str) * len + 1)))
			return (NULL);
		ft_memcpy(new_str[i], str[i], len);
		new_str[i][len] = '\0';
		free(str[i]);
		++i;
	}
	new_str[i] = NULL;
	free(str);
	return (new_str);
}

static int	**set_int_map(t_map *m)
{
	int i;
	int j;
	int **map_i;

	i = 0;
	if (!(map_i = malloc(sizeof(*map_i) * ft_strlen(m->map[i]))))
		return (NULL);
	while (m->map[i])
	{
		j = 0;
		if (!(map_i[i] = malloc(sizeof(**map_i) * ft_strlen(m->map[i]))))
			return (NULL);
		while (m->map[i][j])
		{
			if (ft_strchr("NSWE", m->map[i][j]))
				map_i[i][j] = 0;
			else
				map_i[i][j] = m->map[i][j] - 48;
			if (m->map[i][j] == '2')
				m->sp->nbr += 1;
			++j;
		}
		++i;
	}
	return (map_i);
}

void		set_map(t_map *m, int fd, char *line)
{
	int		i;
	int		len;
	char	*map_line;

	i = 1;
	if (!(m->map = malloc(sizeof(*m->map) * 2)))
		return ;
	m->map[0] = ft_strdup_mod(line);
	m->map[1] = NULL;
	map_line = NULL;
	len = ft_strlen(m->map[0]);
	while (get_next_line(fd, &map_line))
	{
		m->map[i] = ft_strdup_mod(map_line);
		m->map = ft_realloc(m->map, ++i, len);
	}
	free(map_line);
	free(m->map[i]);
	m->map[i] = NULL;
	m->map_i = set_int_map(m);
	m->width = len;
	m->height = i;
}
