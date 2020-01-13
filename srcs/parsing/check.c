/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:22:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 03:38:12 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	check_path(t_map *m)
{
	int		i;
	int		fd;
	size_t	len;

	i = 0;
	while (i < 5)
	{
		if ((fd = open(m->tp[i], O_RDONLY)) == -1)
			print_error(2, m->tp[i], m, 1);
		close(fd);
		len = ft_strlen(m->tp[i]) - 4;
		if (ft_strncmp(m->tp[i] + len, ".xpm", 4) != 0)
			print_error(3, m->tp[i], m, 1);
		++i;
	}
}

void	check_wall(t_map *m, int i)
{
	int j;

	j = 0;
	while (m->map[i][j])
	{
		if (m->map[i][j] != '1')
			print_error(5, &i, m, 1);
		++j;
	}
}

void	check_map(t_map *m)
{
	int i;
	int j;

	i = 0;
	check_wall(m, i);
	while (m->map[i])
	{
		j = 0;
		if ((int)ft_strlen(m->map[i]) != m->width)
			print_error(10, (void *)0, m, 1);
		(m->map[i][j] != '1') ? print_error(5, &i, m, 1) : 1;
		while (m->map[i][j])
		{
			(m->map[i][j] == '2') ? m->sp->nbr += 1 : 0;
			if (!(ft_strchr("012NSEW", m->map[i][j]) ||
						ft_isspace(m->map[i][j])))
				print_error(4, &m->map[i][j], m, 1);
			(ft_strchr("NSEW", m->map[i][j])) ? set_player(m, i, j) : 1;
			++j;
		}
		(m->map[i][j - 1] != '1') ? print_error(5, &i, m, 1) : 1;
		++i;
	}
	check_wall(m, i - 1);
	(m->p->x == 0 && m->p->y == 0) ? print_error(7, (void *)0, m, 1) : 0;
}

void	check_parsing(t_map *m)
{
	(m->re->x <= 0 || m->re->y <= 0) ? (print_error(0, (void *)0, m, 1)) : 1;
	(m->re->x > 2560) ? m->re->x = 2560 : 0;
	(m->re->y > 1418) ? m->re->y = 1418 : 0;
	(m->config_flag != 8) ? print_error(9, (void *)0, m, 1) : 0;
	check_path(m);
	(m->map) ? check_map(m) : 0;
	(m->p->set_flag != 1) ? print_error(6, (void *)0, m, 1) : 0;
	(m->flag_clr == 1) ? print_error(1, (void *)0, m, 1) : 0;
}
