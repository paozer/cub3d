/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_main.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:38:04 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 00:13:56 by pramella    ###    #+. /#+    ###.fr     */
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
		RAY->side_dist_x = ((double)RAY->map_x + 1 - PLAYER->x) *
				RAY->delta_dist_x;
	}
	if (RAY->dir_y < 0)
	{
		RAY->step_y = -1;
		RAY->side_dist_y = (PLAYER->y - (double)RAY->map_y) * RAY->delta_dist_y;
	}
	else
	{
		RAY->step_y = 1;
		RAY->side_dist_y = ((double)RAY->map_y + 1 - PLAYER->y) *
				RAY->delta_dist_y;
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
		if (map->map_i[RAY->map_x][RAY->map_y] == 1)
			RAY->hit = 1;
	}
	if (RAY->side == 0)
		RAY->wall_dist = ((double)RAY->map_x - PLAYER->x +
					(1 - RAY->step_x) / 2) / RAY->dir_x;
	else
		RAY->wall_dist = ((double)RAY->map_y - PLAYER->y +
					(1 - RAY->step_y) / 2) / RAY->dir_y;
}

void	raycasting(t_map *map)
{
	int x;

	x = 0;
	mlx_clear_window(MLX->mlx_ptr, MLX->win_ptr);
	while (x < RES->x)
	{
		SCREEN->cam_x = 2 * x / (double)RES->x - 1;
		RAY->dir_x = PLAYER->dir_x + SCREEN->plane_x * SCREEN->cam_x;
		RAY->dir_y = PLAYER->dir_y + SCREEN->plane_y * SCREEN->cam_x;
		RAY->map_x = (int)PLAYER->x;
		RAY->map_y = (int)PLAYER->y;
		RAY->delta_dist_x = fabs(1 / RAY->dir_x);
		RAY->delta_dist_y = fabs(1 / RAY->dir_y);
		compute_first_section(map);
		compute_wall_hit(map);
		/*
		if (!(SPR->wall_dist[x] = malloc(sizeof(*SPR->wall_dist))))
			return ;
			*/
		SPR->wall_dist[x] = RAY->wall_dist;
		RAY->line_h = (int)(RES->y / RAY->wall_dist);
		draw(map, x);
		++x;
	}
	sprites_main(map);
	mlx_put_image_to_window(MLX->mlx_ptr, MLX->win_ptr, IMG->img, 0, 0);
}

void	start(t_map *map)
{
	raycasting(map);
	if (!(MOVT = malloc(sizeof(*MOVT))))
		return ;
	MOVT->front = 0;
	MOVT->back = 0;
	MOVT->right = 0;
	MOVT->left = 0;
	MOVT->rot_right = 0;
	MOVT->rot_left = 0;
	mlx_loop_hook(MLX->mlx_ptr, movt_do, map);
	mlx_hook(MLX->win_ptr, 2, 0, movt_pressed, map);
	mlx_hook(MLX->win_ptr, 3, 0, movt_released, map);
	mlx_hook(MLX->win_ptr, 17, 0, free_dummy, map);
	mlx_loop(MLX->mlx_ptr);
}
