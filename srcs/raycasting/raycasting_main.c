/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_main.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/12 01:38:04 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 03:30:39 by pramella    ###    #+. /#+    ###.fr     */
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
		PLAYER->cam_x = 2 * x / map->res_ptr->x - 1;
		PLAYER->ray_dir_x = PLAYER->dir_x + PLAYER->plane_x * PLAYER->cam_x;
		PLAYER->ray_dir_y = PLAYER->dir_y + PLAYER->plane_y * PLAYER->cam_y;
	}
}
