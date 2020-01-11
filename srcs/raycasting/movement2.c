/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_movt2.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 16:13:03 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 19:46:56 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	movt_front_back(int key_code, t_map *m)
{
	int new_x;
	int new_y;

	if (key_code == 13)
	{
		new_x = (int)(m->p->x + m->p->dir_x * SPEED);
		new_y = (int)(m->p->y + m->p->dir_y * SPEED);
		if (m->map_i[new_x][new_y] == 1)
			return ;
		m->p->x += m->p->dir_x * SPEED;
		m->p->y += m->p->dir_y * SPEED;
	}
	if (key_code == 1)
	{
		new_x = (int)(m->p->x - m->p->dir_x * SPEED);
		new_y = (int)(m->p->y - m->p->dir_y * SPEED);
		if (m->map_i[new_x][new_y] == 1)
			return ;
		m->p->x -= m->p->dir_x * SPEED;
		m->p->y -= m->p->dir_y * SPEED;
	}
}

void	movt_left_right(int key_code, t_map *m)
{
	int new_x;
	int new_y;

	if (key_code == 0)
	{
		new_x = (int)(m->p->x - m->p->dir_y * SPEED);
		new_y = (int)(m->p->y + m->p->dir_x * SPEED);
		if (m->map_i[new_x][new_y] == 1)
			return ;
		m->p->x -= m->p->dir_y * SPEED;
		m->p->y += m->p->dir_x * SPEED;
	}
	if (key_code == 2)
	{
		new_x = (int)(m->p->x + m->p->dir_y * SPEED);
		new_y = (int)(m->p->y - m->p->dir_x * SPEED);
		if (m->map_i[new_x][new_y] == 1)
			return ;
		m->p->x += m->p->dir_y * SPEED;
		m->p->y -= m->p->dir_x * SPEED;
	}
}

int		rot_left_right(int key_code, t_map *m)
{
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;

	dir_x = m->p->dir_x;
	dir_y = m->p->dir_y;
	plane_x = m->s->plane_x;
	plane_y = m->s->plane_y;
	if (key_code == 123)
	{
		m->p->dir_x = cos(ROTSPEED) * dir_x - sin(ROTSPEED) * dir_y;
		m->p->dir_y = sin(ROTSPEED) * dir_x + cos(ROTSPEED) * dir_y;
		m->s->plane_x = cos(ROTSPEED) * plane_x - sin(ROTSPEED) * plane_y;
		m->s->plane_y = sin(ROTSPEED) * plane_x + cos(ROTSPEED) * plane_y;
	}
	if (key_code == 124)
	{
		m->p->dir_x = cos(ROTSPEED) * dir_x + sin(ROTSPEED) * dir_y;
		m->p->dir_y = cos(ROTSPEED) * dir_y - sin(ROTSPEED) * dir_x;
		m->s->plane_x = cos(ROTSPEED) * plane_x + sin(ROTSPEED) * plane_y;
		m->s->plane_y = cos(ROTSPEED) * plane_y - sin(ROTSPEED) * plane_x;
	}
	return (0);
}
