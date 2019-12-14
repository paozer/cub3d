/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_main.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:38:04 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 18:11:54 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	compute_first_section(t_map *map)
{
	if (RAY->dir_x < 0)
	{
		RAY->step_x = -1;
		RAY->side_dist_x = (PLAYER->x - (double)RAY->map_x) * RAY->delta_dist_x;
	}
	else
	{
		RAY->step_x = 1;
		RAY->side_dist_x = ((double)RAY->map_x + 1 - PLAYER->x) * RAY->delta_dist_x;
	}
	if (RAY->dir_y < 0)
	{
		RAY->step_y = -1;
		RAY->side_dist_y = (PLAYER->y - (double)RAY->map_y) * RAY->delta_dist_y;
	}
	else
	{
		RAY->step_y = 1;
		RAY->side_dist_y = ((double)RAY->map_y + 1 - PLAYER->y) * RAY->delta_dist_y;
	}
}

void	compute_wall_hit(t_map *map)
{
	RAY->hit = 0;
	while (RAY->hit == 0)
	{
		if (RAY->side_dist_x < RAY->side_dist_y)
		{
			RAY->side_dist_x += RAY->delta_dist_x;
			RAY->map_x += RAY->step_x;
			RAY->side = 0;
		}
		else
		{
			RAY->side_dist_y += RAY->delta_dist_y;
			RAY->map_y += RAY->step_y;
			RAY->side = 1;
		}
		if (map->map_i[RAY->map_y][RAY->map_x] >= 1)
			RAY->hit = 1;
	}
	if (RAY->side == 0)
		RAY->wall_dist = ((double)RAY->map_x - PLAYER->x + (1 - RAY->step_x) / 2) / RAY->dir_x;
	else
		RAY->wall_dist = ((double)RAY->map_y - PLAYER->y + (1 - RAY->step_y) / 2) / RAY->dir_y;
}

void	ft_raycasting(t_map *map)
{
	int x;
	int line_h;

	x = 0;
	while (x < map->res_ptr->x)
	{
		SCREEN->cam_x = 2 * x / (double)map->res_ptr->x - 1;
		RAY->dir_x = PLAYER->dir_x + SCREEN->plane_x * SCREEN->cam_x;
		RAY->dir_y = PLAYER->dir_y + SCREEN->plane_y * SCREEN->cam_x;
		RAY->map_x = (int)PLAYER->x;
		RAY->map_y = (int)PLAYER->y;
		RAY->delta_dist_x = ft_abs(1 / RAY->dir_x);
		RAY->delta_dist_y = ft_abs(1 / RAY->dir_y);
		compute_first_section(map);
		compute_wall_hit(map);
		RAY->line_h = (int) (map->map_height / RAY->wall_dist);
		draw(map);
		++x;
	}
}

/*
printf("RAY->dir_x = [%f] RAY->dir_y = [%f]\n", RAY->dir_x, RAY->dir_y);
printf("SCREEN->cam_x = [%f]\n", SCREEN->cam_x);
printf("SCREEN->cam_x = [%f]\n", SCREEN->cam_x);
printf("RAY->dir_x = [%f]\n", RAY->dir_x);
printf("RAY->dir_y = [%f]\n", RAY->dir_y);
printf("RAY->map_x = [%d]\n", RAY->map_x);
printf("RAY->map_y = [%d]\n", RAY->map_y);
printf("RAY->delta_dist_x = [%f]\n", RAY->delta_dist_x);
printf("RAY->delta_dist_y = [%f]\n", RAY->delta_dist_y);
printf("RAY->step_x = [%f]\n", RAY->step_x);
printf("RAY->step_y = [%f]\n", RAY->step_y);
printf("RAY->side_dist_x = [%f]\n", RAY->side_dist_x);
printf("RAY->side_dist_y = [%f]\n", RAY->side_dist_y);
*/
