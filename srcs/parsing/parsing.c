/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 19:29:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 02:23:47 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void		set_resolution(char *line, t_map *m)
{
	int i;

	i = 0;
	while (line[i] && ft_isspace(line[i]))
		++i;
	m->re->x = ft_atoi(line + i);
	while (ft_isdigit(line[i]))
		++i;
	while (line[i] && ft_isspace(line[i]))
		++i;
	m->re->y = ft_atoi(line + i);
	++m->config_flag;
}

static void		set_color(char *line, t_map *m, int flag)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = 0;
	r = -1;
	g = -1;
	b = -1;
	ft_atoi_pos_return(line, &r, &i);
	ft_atoi_pos_return(line, &g, &i);
	ft_atoi_pos_return(line, &b, &i);
	(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) ?
		m->flag_clr = 1 : 0;
	(flag == 1) ? (*m->cc = (r << 16) | (g << 8) | (b)) :
		(*m->fc = (r << 16) | (g << 8) | (b));
	++m->config_flag;
}

void			set_player(t_map *m, int x, int y)
{
	m->p->set_flag++;
	m->p->x = x + .5;
	m->p->y = y + .5;
	if (m->map[x][y] == 'N' || m->map[x][y] == 'S')
	{
		m->p->dir_y = 0;
		m->p->dir_x = (m->map[x][y] == 'N') ? -1 : 1;
		m->s->plane_x = 0;
		m->s->plane_y = (m->map[x][y] == 'N') ? .66 : -.66;
	}
	if (m->map[x][y] == 'W' || m->map[x][y] == 'E')
	{
		m->p->dir_x = 0;
		m->p->dir_y = (m->map[x][y] == 'W') ? -1 : 1;
		m->s->plane_y = 0;
		m->s->plane_x = (m->map[x][y] == 'W') ? -.66 : .66;
	}
}

char			*gnl_file(t_map *m, int fd, int i)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		i = 0;
		while (line[i] && ft_isspace(line[i]) == 1)
			++i;
		(line[i] == 'R') ? set_resolution(line + i + 1, m) : 1;
		(line[i] == 'N' && line[i + 1] == 'O') ?
			(m->tp[0] = set_paths(line + 2, m)) : 0;
		(line[i] == 'S' && line[i + 1] == 'O') ?
			(m->tp[1] = set_paths(line + 2, m)) : 0;
		(line[i] == 'W' && line[i + 1] == 'E') ?
			(m->tp[2] = set_paths(line + 2, m)) : 0;
		(line[i] == 'E' && line[i + 1] == 'A') ?
			(m->tp[3] = set_paths(line + 2, m)) : 0;
		(line[i] == 'S' && line[i + 1] != 'O') ?
			(m->tp[4] = set_paths(line + 1, m)) : 0;
		(line[i] == 'F') ? set_color(line + 2, m, 0) : 0;
		(line[i] == 'C') ? set_color(line + 2, m, 1) : 0;
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
	t_map	*m;

	i = 0;
	line = NULL;
	m = init_map();
	if ((fd = open(params, O_RDONLY)) == -1)
		print_error(2, params, m, 1);
	(ft_strncmp(params + ft_strlen(params) - 4, ".cub", 4) != 0) ?
		print_error(3, params, m, 1) : 1;
	line = gnl_file(m, fd, i);
	set_map(m, fd, line);
	check_parsing(m);
	close(fd);
	return (m);
}
