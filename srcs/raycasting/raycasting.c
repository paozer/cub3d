/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:38:04 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 06:35:33 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_first_section(t_map *m)
{
	if (m->ra->dir_x < 0)
	{
		m->ra->step_x = -1;
		m->ra->side_dist_x = (m->p->x - (double)m->ra->map_x) *
			m->ra->delta_dist_x;
	}
	else
	{
		m->ra->step_x = 1;
		m->ra->side_dist_x = ((double)m->ra->map_x + 1 - m->p->x) *
			m->ra->delta_dist_x;
	}
	if (m->ra->dir_y < 0)
	{
		m->ra->step_y = -1;
		m->ra->side_dist_y = (m->p->y - (double)m->ra->map_y) *
			m->ra->delta_dist_y;
	}
	else
	{
		m->ra->step_y = 1;
		m->ra->side_dist_y = ((double)m->ra->map_y + 1 - m->p->y) *
			m->ra->delta_dist_y;
	}
}

void	compute_wall_hit(t_map *m)
{
	m->ra->hit = 0;
	while (m->ra->hit == 0)
	{
		if (m->ra->side_dist_x < m->ra->side_dist_y)
		{
			m->ra->side_dist_x += m->ra->delta_dist_x;
			m->ra->map_x += m->ra->step_x;
			m->ra->side = 0;
		}
		else
		{
			m->ra->side_dist_y += m->ra->delta_dist_y;
			m->ra->map_y += m->ra->step_y;
			m->ra->side = 1;
		}
		if (m->map_i[m->ra->map_x][m->ra->map_y] == 1)
			m->ra->hit = 1;
	}
	if (m->ra->side == 0)
		m->ra->wall_dist = ((double)m->ra->map_x - m->p->x +
				(1 - m->ra->step_x) / 2) / m->ra->dir_x;
	else
		m->ra->wall_dist = ((double)m->ra->map_y - m->p->y +
				(1 - m->ra->step_y) / 2) / m->ra->dir_y;
}

void	raycasting(t_map *m)
{
	int x;

	x = 0;
	if (m->save == 0)
		mlx_clear_window(m->mx->mlx_ptr, m->mx->win_ptr);
	while (x < m->re->x)
	{
		m->s->cam_x = 2 * x / (double)m->re->x - 1;
		m->ra->dir_x = m->p->dir_x + m->s->plane_x * m->s->cam_x;
		m->ra->dir_y = m->p->dir_y + m->s->plane_y * m->s->cam_x;
		m->ra->map_x = (int)m->p->x;
		m->ra->map_y = (int)m->p->y;
		m->ra->delta_dist_x = fabs(1 / m->ra->dir_x);
		m->ra->delta_dist_y = fabs(1 / m->ra->dir_y);
		compute_first_section(m);
		compute_wall_hit(m);
		m->sp->wall_dist[x] = m->ra->wall_dist;
		m->ra->line_h = (int)(m->re->y / m->ra->wall_dist);
		draw(m, x);
		++x;
	}
	sprites_main(m);
	if (m->save == 1)
		map_to_bmp(m);
	mlx_put_image_to_window(m->mx->mlx_ptr, m->mx->win_ptr, m->i->img, 0, 0);
}

void	start(t_map *m)
{
	raycasting(m);
	if (!(m->mo = malloc(sizeof(*m->mo))))
		return ;
	m->mo->front = 0;
	m->mo->back = 0;
	m->mo->right = 0;
	m->mo->left = 0;
	m->mo->rot_right = 0;
	m->mo->rot_left = 0;
	mlx_loop_hook(m->mx->mlx_ptr, movt_do, m);
	mlx_hook(m->mx->win_ptr, 2, 0, movt_pressed, m);
	mlx_hook(m->mx->win_ptr, 3, 0, movt_released, m);
	mlx_hook(m->mx->win_ptr, 17, 0, free_dummy, m);
	mlx_loop(m->mx->mlx_ptr);
}
