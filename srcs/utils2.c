/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils2.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 03:31:34 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 10:39:01 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int flag, void *arg, t_map *map, int free_flag)
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
	(flag == 6) ? ft_printf("Multiple or no start positions for player.\n") : 1;
	(flag == 7) ? ft_printf("No start position for player.\n") : 1;
	(flag == 8) ? ft_printf("Could not allocate sufficient memory.\n") : 1;
	(flag == 9) ? ft_printf("Multiple or missing specifications.\n") : 1;
	free_all(map, free_flag);
}

char	*set_paths(char *line, t_map *map)
{
	int		i;
	char	*str;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	str = ft_strdup(line + i);
	++map->config_flag;
	return (str);
}

int		ft_strlen_mod(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			++j;
		++i;
	}
	return (j);
}

char	*ft_strdup_mod(char *str)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!(s = malloc(sizeof(*s) * ft_strlen_mod(str) + 1)))
		return (NULL);
	while (str[i])
	{
		if (ft_isspace(str[i]) == 0)
			s[j++] = str[i];
		++i;
	}
	s[j] = '\0';
	free(str);
	return (s);
}
