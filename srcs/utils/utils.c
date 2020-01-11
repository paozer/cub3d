/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 03:31:34 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 07:10:20 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int flag, void *arg, t_map *m, int free_flag)
{
	write(1, "Error\n", 6);
	(flag == 0) ? ft_printf("Resolution is not valid.\n") : 1;
	(flag == 1) ? ft_printf("Specified colors are not in the RGB range.\n") : 1;
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
	(flag == 10) ? ft_printf("Map rows are not of equal length.\n") : 1;
	(flag == 11) ? ft_printf("Second argument is invalid.\n") : 1;
	free_all(m, free_flag);
}

char	*set_paths(char *line, t_map *m, int t)
{
	int		i;
	char	*str;

	i = 0;
	if (m->tp[t])
		free(m->tp[t]);
	while (line[i] && ft_isspace(line[i]))
		++i;
	str = ft_strdup(line + i);
	++m->config_flag;
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

void	ft_atoi_pos_return(char *s, int *n, int *i)
{
	while (s[*i] && (ft_isspace(s[*i]) || s[*i] == ','))
		*i += 1;
	if (s[*i] && ft_isdigit(s[*i]))
		*n = ft_atoi(s + *i);
	while (s[*i] && ft_isdigit(s[*i]))
		*i += 1;
}
