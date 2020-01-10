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

void	movt_front_back(int key_code, t_map *map)
{
	int new_x;
	int new_y;

	if (key_code == 13)
	{
		new_x = (int)(map->p->x + map->p->dir_x * SPEED);
		new_y = (int)(map->p->y + map->p->dir_y * SPEED);
		if (map->map_i[new_x][new_y] == 1)
			return ;
		map->p->x += map->p->dir_x * SPEED;
		map->p->y += map->p->dir_y * SPEED;
	}
	if (key_code == 1)
	{
		new_x = (int)(map->p->x - map->p->dir_x * SPEED);
		new_y = (int)(map->p->y - map->p->dir_y * SPEED);
		if (map->map_i[new_x][new_y] == 1)
			return ;
		map->p->x -= map->p->dir_x * SPEED;
		map->p->y -= map->p->dir_y * SPEED;
	}
}

void	movt_left_right(int key_code, t_map *map)
{
	int new_x;
	int new_y;

	if (key_code == 0)
	{
		new_x = (int)(map->p->x - map->p->dir_y * SPEED);
		new_y = (int)(map->p->y + map->p->dir_x * SPEED);
		if (map->map_i[new_x][new_y] == 1)
			return ;
		map->p->x -= map->p->dir_y * SPEED;
		map->p->y += map->p->dir_x * SPEED;
	}
	if (key_code == 2)
	{
		new_x = (int)(map->p->x + map->p->dir_y * SPEED);
		new_y = (int)(map->p->y - map->p->dir_x * SPEED);
		if (map->map_i[new_x][new_y] == 1)
			return ;
		map->p->x += map->p->dir_y * SPEED;
		map->p->y -= map->p->dir_x * SPEED;
	}
}

int		rot_left_right(int key_code, t_map *map)
{
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;

	dir_x = map->p->dir_x;
	dir_y = map->p->dir_y;
	plane_x = map->s->plane_x;
	plane_y = map->s->plane_y;
	if (key_code == 123)
	{
		map->p->dir_x = cos(ROTSPEED) * dir_x - sin(ROTSPEED) * dir_y;
		map->p->dir_y = sin(ROTSPEED) * dir_x + cos(ROTSPEED) * dir_y;
		map->s->plane_x = cos(ROTSPEED) * plane_x - sin(ROTSPEED) * plane_y;
		map->s->plane_y = sin(ROTSPEED) * plane_x + cos(ROTSPEED) * plane_y;
	}
	if (key_code == 124)
	{
		map->p->dir_x = cos(ROTSPEED) * dir_x + sin(ROTSPEED) * dir_y;
		map->p->dir_y = cos(ROTSPEED) * dir_y - sin(ROTSPEED) * dir_x;
		map->s->plane_x = cos(ROTSPEED) * plane_x + sin(ROTSPEED) * plane_y;
		map->s->plane_y = cos(ROTSPEED) * plane_y - sin(ROTSPEED) * plane_x;
	}
	return (0);
}
