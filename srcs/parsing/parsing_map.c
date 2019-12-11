/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 20:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 03:41:10 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

static char	**ft_realloc(char **str, int size, int len)
{
	int		i;
	char	**new_str;

	i = 0;
	if (!(new_str = malloc(sizeof(*new_str) * (size + 1))))
		return (NULL);
	while (i < size)
	{
		if (!(new_str[i] = malloc(sizeof(**new_str) * len)))
			return (NULL);
		ft_memcpy(new_str[i], str[i], len);
		new_str[i][len - 1] = '\0';
		free(str[i]);
		++i;
	}
	free(str);
	return (new_str);
}

int			**ft_set_int_map(char **map)
{
	int i;
	int j;
	int k;
	int **map_i;

	i = 0;
	k = 0;
	while (map[i])
		++i;
	if (!(map_i = malloc(sizeof(*map_i) * i)))
		return (NULL);
	i = 0;
	while (map[i])
	{
		j = 0;
		map_i[i] = malloc(sizeof(**map_i) * ft_strlen(map[i]))
		while (map[i][j])
		{
		}
	}
}

char		**ft_set_map(int fd, char **line)
{
	int		i;
	int		len;
	char	**map;

	i = 1;
	if (!(map = malloc(sizeof(*map) * 2)))
		return (NULL);
	map[0] = *line;
	len = ft_strlen(*line);
	while (get_next_line(fd, &map[i]) == 1)
		map = ft_realloc(map, ++i, len);
	free(map[i]);
	map[i] = NULL;
	return (map);
}
