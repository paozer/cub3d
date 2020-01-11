/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 18:32:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 01:08:39 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map(void)
{
	t_map	*m;

	if (!(m = malloc(sizeof(*m))))
		print_error(8, NULL, NULL, 0);
	m->fc = malloc(sizeof(*m->fc));
	m->cc = malloc(sizeof(*m->cc));
	m->flag_clr = 0;
	m->mx = malloc(sizeof(*m->mx));
	m->re = malloc(sizeof(*m->re));
	m->s = malloc(sizeof(*m->s));
	m->p = malloc(sizeof(*m->p));
	(m->p) ? m->p->set_flag = 0 : 0;
	m->ra = malloc(sizeof(*m->ra));
	m->sp = malloc(sizeof(*m->sp));
	m->sp->nbr = 0;
	m->save = 0;
	m->config_flag = 0;
	if (!(m && m->fc && m->cc && m->mx && m->re &&
				m->s && m->p && m->ra && m->sp))
		print_error(8, NULL, m, 1);
	return (m);
}

void	init_sprites(t_map *m)
{
	int i;
	int j;
	int y;

	if (!(m->sp->arr = malloc(sizeof(*m->sp->arr) * (m->sp->nbr + 1))))
		return ;
	m->sp->arr[m->sp->nbr] = NULL;
	i = -1;
	y = 0;
	while (++i < m->height)
	{
		j = -1;
		while (++j < m->width)
		{
			if (m->map_i[i][j] == 2)
			{
				if (!(m->sp->arr[y] = malloc(sizeof(*m->sp->arr[y]))))
					return ;
				m->sp->arr[y]->x = i + .5;
				m->sp->arr[y++]->y = j + .5;
			}
		}
	}
	if (!(m->sp->wall_dist = malloc(sizeof(*m->sp->wall_dist) * m->re->x)))
		return ;
}

void	init(t_map *m)
{
	int i;

	i = 0;
	if ((m->mx->mlx_ptr = mlx_init()) == NULL)
		return ;
	if ((m->mx->win_ptr = mlx_new_window(m->mx->mlx_ptr, m->re->x, m->re->y,
					"cube3d")) == NULL)
		return ;
	if (!(m->i = malloc(sizeof(*(m->i)))))
		return ;
	m->i->img = mlx_new_image(m->mx->mlx_ptr, m->re->x, m->re->y);
	m->i->buf = (int *)mlx_get_data_addr(m->i->img, &m->i->bpp,
			&m->i->size_line, &m->i->endian);
	while (i < 5)
	{
		if (!(m->t[i] = malloc(sizeof(t_img))))
			return ;
		m->t[i]->img = mlx_xpm_file_to_image(m->mx->mlx_ptr, m->tp[i],
				&m->t[i]->width, &m->t[i]->height);
		m->t[i]->buf = (int *)mlx_get_data_addr(m->t[i]->img, &m->t[i]->bpp,
				&m->t[i]->size_line, &m->t[i]->endian);
		++i;
	}
}
