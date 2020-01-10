/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   movement.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/18 12:40:53 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 03:18:38 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int	movt_do(t_map *map)
{
	(map->mo->front == 1) ? movt_front_back(13, map) : 0;
	(map->mo->back == 1) ? movt_front_back(1, map) : 0;
	(map->mo->left == 1) ? movt_left_right(0, map) : 0;
	(map->mo->right == 1) ? movt_left_right(2, map) : 0;
	(map->mo->rot_left == 1) ? rot_left_right(123, map) : 0;
	(map->mo->rot_right == 1) ? rot_left_right(124, map) : 0;
	raycasting(map);
	return (0);
}

int	movt_pressed(int key_code, t_map *map)
{
	if (key_code == 53)
		free_all(map, 2);
	(key_code == 13 || key_code == 126) ? map->mo->front = 1 : 0;
	(key_code == 1 || key_code == 125) ? map->mo->back = 1 : 0;
	(key_code == 0) ? map->mo->left = 1 : 0;
	(key_code == 2) ? map->mo->right = 1 : 0;
	(key_code == 123) ? map->mo->rot_left = 1 : 0;
	(key_code == 124) ? map->mo->rot_right = 1 : 0;
	movt_do(map);
	return (0);
}

int	movt_released(int key_code, t_map *map)
{
	(key_code == 13 || key_code == 126) ? map->mo->front = 0 : 0;
	(key_code == 1 || key_code == 125) ? map->mo->back = 0 : 0;
	(key_code == 0) ? map->mo->left = 0 : 0;
	(key_code == 2) ? map->mo->right = 0 : 0;
	(key_code == 123) ? map->mo->rot_left = 0 : 0;
	(key_code == 124) ? map->mo->rot_right = 0 : 0;
	movt_do(map);
	return (0);
}
