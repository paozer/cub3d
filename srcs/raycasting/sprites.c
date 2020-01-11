/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sprites.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 21:45:59 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 02:30:20 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites_select_pixel(t_map *m, int j)
{
	int y;
	int d;
	int color;

	if (m->sp->trans_y > 0 && j > 0 && j < m->re->x &&
			m->sp->trans_y < m->sp->wall_dist[j])
	{
		y = m->sp->draw_start_y;
		while (y < m->sp->draw_end_y)
		{
			d = y * 256 - m->re->y * 128 + m->sp->height * 128;
			m->sp->tex_y = ((d * m->t[4]->width) / m->sp->height) / 256;
			if (m->t[4]->width * m->t[4]->height >
					m->sp->tex_y * m->t[4]->width + m->sp->tex_x)
			{
				color = m->t[4]->buf[m->sp->tex_y *
					m->t[4]->width + m->sp->tex_x];
				if (color != 0)
					m->i->buf[y * m->re->x + j] = color;
			}
			++y;
		}
	}
}

void	sprites_start_end(t_map *m)
{
	m->sp->height = abs((int)(m->re->y / m->sp->trans_y));
	m->sp->draw_start_y = -m->sp->height / 2 + m->re->y / 2;
	(m->sp->draw_start_y < 0) ? m->sp->draw_start_y = 0 : 0;
	m->sp->draw_end_y = m->sp->height / 2 + m->re->y / 2;
	(m->sp->draw_end_y >= m->re->y) ? m->sp->draw_end_y = m->re->y - 1 : 0;
	m->sp->width = abs((int)(m->re->y / m->sp->trans_y));
	m->sp->draw_start_x = -m->sp->width / 2 + m->sp->screen_x;
	(m->sp->draw_start_x < 0) ? m->sp->draw_start_x = 0 : 0;
	m->sp->draw_end_x = m->sp->width / 2 + m->sp->screen_x;
	(m->sp->draw_end_x >= m->re->x) ? m->sp->draw_end_x = m->re->x - 1 : 0;
}

void	sprites_draw(t_map *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->sp->nbr)
	{
		m->sp->x = m->sp->arr[i]->x - m->p->x;
		m->sp->y = m->sp->arr[i++]->y - m->p->y;
		m->sp->inv_deter = 1.0 / (m->s->plane_x * m->p->dir_y -
				m->p->dir_x * m->s->plane_y);
		m->sp->trans_x = m->sp->inv_deter *
			(m->p->dir_y * m->sp->x - m->p->dir_x * m->sp->y);
		m->sp->trans_y = m->sp->inv_deter *
			(-m->s->plane_y * m->sp->x + m->s->plane_x * m->sp->y);
		m->sp->screen_x = (int)((m->re->x / 2) *
				(1 + m->sp->trans_x / m->sp->trans_y));
		sprites_start_end(m);
		j = m->sp->draw_start_x;
		while (j < m->sp->draw_end_x)
		{
			m->sp->tex_x = (int)(256 * (j - (-m->sp->width / 2 +
				m->sp->screen_x)) * m->t[4]->height / m->sp->width) / 256;
			sprites_select_pixel(m, j++);
		}
	}
}

void	sprites_sort(t_map *m)
{
	int		i;
	t_spr	*tmp;

	i = 0;
	while (m->sp->arr[i] && m->sp->arr[i + 1])
	{
		if (m->sp->arr[i]->dist < m->sp->arr[i + 1]->dist)
		{
			tmp = m->sp->arr[i + 1];
			m->sp->arr[i + 1] = m->sp->arr[i];
			m->sp->arr[i] = tmp;
			i = 0;
		}
		++i;
	}
}

void	sprites_main(t_map *m)
{
	int i;

	i = 0;
	while (m->sp->arr[i])
	{
		m->sp->arr[i]->dist = pow(m->p->x - m->sp->arr[i]->x, 2)
			+ pow(m->p->y - m->sp->arr[i]->y, 2);
		++i;
	}
	sprites_sort(m);
	sprites_draw(m);
}
