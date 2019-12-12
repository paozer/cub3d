/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_main.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:38:04 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 16:54:12 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_raycasting(t_map *map)
{
	int x;

	x = 0;
	while (x < map->res_ptr->x)
	{
		SCREEN->cam_x = 2 * x / map->res_ptr->x - 1;
		RAY->dir_x = PLAYER->dir_x + SCREEN->plane_x * SCREEN->cam_x;
		RAY->dir_y = PLAYER->dir_y + SCREEN->plane_y * SCREEN->cam_y;

		RAY->map_x = (int)PLAYER->x;
		RAY->map_y = (int)PLAYER->y;
		RAY->delta_dist_x = ft_abs(1 / RAY->dir_x);
		RAY->delta_dist_y = ft_abs(1 / RAY->dir_y);

		if (RAY->dir_x < 0)
		{
			RAY->step_x = -1;
			RAY->side_dist_x = (PLAYER->x - RAY->map_x) * RAY->delta_dist_x;
		}
		else
		{
			RAY->step_x = 1;
			RAY->side_dist_x = (RAY->map_x + 1 - PLAYER->x) * RAY->delta_dist_x;
		}
		if (RAY->dir_y < 0)
		{
			RAY->step_y = -1;
			RAY->side_dist_y = (PLAYER->y - RAY->map_y) * RAY->delta_dist_y;
		}
		else
		{
			RAY->step_y = 1;
			RAY->side_dist_y = (RAY->map_y + 1 - PLAYER->y) * RAY->delta_dist_y;
		}

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
			if (map->map_i[RAY->map_y][RAY->map_x] == 1)
				RAY->hit = 1;
		}
		if (RAY->side == 0)
			RAY->wall_dist = (RAY->map_x - PLAYER->x + (1 - RAY->step_x) / 2) / RAY->dir_x;
		else
			RAY->wall_dist = (RAY->map_y - PLAYER->y + (1 - RAY->step_y) / 2) / RAY->dir_y;

		int line_h = (int) (map->map_height / RAY->wall_dist);
		(void)line_h;
	}
}
