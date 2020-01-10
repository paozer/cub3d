/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:38:04 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 06:25:26 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	compute_first_section(t_map *map)
{
	if (map->ra->dir_x < 0)
	{
		map->ra->step_x = -1;
		map->ra->side_dist_x = (map->p->x - (double)map->ra->map_x) * map->ra->delta_dist_x;
	}
	else
	{
		map->ra->step_x = 1;
		map->ra->side_dist_x = ((double)map->ra->map_x + 1 - map->p->x) *
			map->ra->delta_dist_x;
	}
	if (map->ra->dir_y < 0)
	{
		map->ra->step_y = -1;
		map->ra->side_dist_y = (map->p->y - (double)map->ra->map_y) * map->ra->delta_dist_y;
	}
	else
	{
		map->ra->step_y = 1;
		map->ra->side_dist_y = ((double)map->ra->map_y + 1 - map->p->y) *
			map->ra->delta_dist_y;
	}
}

void	compute_wall_hit(t_map *map)
{
	map->ra->hit = 0;
	while (map->ra->hit == 0)
	{
		if (map->ra->side_dist_x < map->ra->side_dist_y)
		{
			map->ra->side_dist_x += map->ra->delta_dist_x;
			map->ra->map_x += map->ra->step_x;
			map->ra->side = 0;
		}
		else
		{
			map->ra->side_dist_y += map->ra->delta_dist_y;
			map->ra->map_y += map->ra->step_y;
			map->ra->side = 1;
		}
		if (map->map_i[map->ra->map_x][map->ra->map_y] == 1)
			map->ra->hit = 1;
	}
	if (map->ra->side == 0)
		map->ra->wall_dist = ((double)map->ra->map_x - map->p->x +
				(1 - map->ra->step_x) / 2) / map->ra->dir_x;
	else
		map->ra->wall_dist = ((double)map->ra->map_y - map->p->y +
				(1 - map->ra->step_y) / 2) / map->ra->dir_y;
}

void	raycasting(t_map *map)
{
	int x;

	x = 0;
	mlx_clear_window(map->mx->mlx_ptr, map->mx->win_ptr);
	while (x < map->re->x)
	{
		map->s->cam_x = 2 * x / (double)map->re->x - 1;
		map->ra->dir_x = map->p->dir_x + map->s->plane_x * map->s->cam_x;
		map->ra->dir_y = map->p->dir_y + map->s->plane_y * map->s->cam_x;
		map->ra->map_x = (int)map->p->x;
		map->ra->map_y = (int)map->p->y;
		map->ra->delta_dist_x = fabs(1 / map->ra->dir_x);
		map->ra->delta_dist_y = fabs(1 / map->ra->dir_y);
		compute_first_section(map);
		compute_wall_hit(map);
		map->sp->wall_dist[x] = map->ra->wall_dist;
		map->ra->line_h = (int)(map->re->y / map->ra->wall_dist);
		draw(map, x);
		++x;
	}
	sprites_main(map);
	if (map->save == 1)
		map_to_bmp(map);
	mlx_put_image_to_window(map->mx->mlx_ptr, map->mx->win_ptr, map->i->img, 0, 0);
}

void	start(t_map *map)
{
	raycasting(map);
	if (!(map->mo = malloc(sizeof(*map->mo))))
		return ;
	map->mo->front = 0;
	map->mo->back = 0;
	map->mo->right = 0;
	map->mo->left = 0;
	map->mo->rot_right = 0;
	map->mo->rot_left = 0;
	mlx_loop_hook(map->mx->mlx_ptr, movt_do, map);
	mlx_hook(map->mx->win_ptr, 2, 0, movt_pressed, map);
	mlx_hook(map->mx->win_ptr, 3, 0, movt_released, map);
	mlx_hook(map->mx->win_ptr, 17, 0, free_dummy, map);
	mlx_loop(map->mx->mlx_ptr);
}
