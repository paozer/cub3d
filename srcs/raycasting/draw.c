/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 04:59:48 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int			select_texture(t_map *m)
{
	int i;

	i = 0;
	(m->ra->side == 0 && m->ra->dir_x > 0) ? (i = 0) : 0;
	(m->ra->side == 0 && m->ra->dir_x < 0) ? (i = 1) : 0;
	(m->ra->side == 1 && m->ra->dir_y < 0) ? (i = 2) : 0;
	(m->ra->side == 1 && m->ra->dir_y > 0) ? (i = 3) : 0;
	return (i);
}

void		select_pixel_while(t_map *m, int x, int y, int i)
{
	int d;
	int color;

	while (y < m->i->draw_end)
	{
		d = y * 256 - m->re->y * 128 + m->ra->line_h * 128;
		m->i->tex_y = d * m->t[i]->height / m->ra->line_h / 256;
		m->i->tex_y < 0 ? m->i->tex_y = 0 : 0;
		if (m->t[i]->height * m->t[i]->width >
				m->i->tex_y * m->t[i]->height + m->i->tex_x)
		{
			color = m->t[i]->buf[m->i->tex_y * m->t[i]->height + m->i->tex_x];
			m->i->buf[y * m->re->x + x] = color;
		}
		y++;
	}
}

void		select_pixel(t_map *m, int i, int x, int y)
{
	m->i->wall_x = (m->ra->side) ? m->p->x + m->ra->wall_dist * m->ra->dir_x :
		m->p->y + m->ra->wall_dist * m->ra->dir_y;
	m->i->wall_x -= floor(m->i->wall_x);
	m->i->tex_x = (int)(m->i->wall_x * (double)m->t[i]->width);
	((m->ra->side == 0 && m->ra->dir_x > 0) ||
		(m->ra->side == 1 && m->ra->dir_y < 0)) ?
		m->i->tex_x = m->t[i]->width - m->i->tex_x - 1 : 0;
	select_pixel_while(m, x, y, i);
}

void		draw(t_map *m, int x)
{
	int		y;
	int		text_index;

	y = 0;
	m->i->draw_start = (m->re->y - m->ra->line_h) / 2;
	m->i->draw_end = (m->re->y + m->ra->line_h) / 2;
	m->i->draw_start = (m->i->draw_start > 0) ? m->i->draw_start : 0;
	m->i->draw_end = (m->i->draw_end > m->re->y) ?
		m->re->y : m->i->draw_end;
	text_index = select_texture(m);
	while (y < m->re->y)
	{
		if (y < m->i->draw_start)
			m->i->buf[y * m->re->x + x] = *m->cc;
		if (y >= m->i->draw_start && y <= m->i->draw_end)
		{
			select_pixel(m, text_index, x, y);
			y = m->i->draw_end;
		}
		if (y > m->i->draw_end)
			m->i->buf[y * m->re->x + x] = *m->fc;
		++y;
	}
}
