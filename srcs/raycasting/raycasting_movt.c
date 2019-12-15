/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_movt.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 16:13:03 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 22:09:47 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int		movt_front_back(int key_code, t_map *map)
{
	if (key_code == 13)
	{
		PLAYER->x += (map->map_i[(int)(PLAYER->x + PLAYER->dir_x * SPEED)]
					[(int)PLAYER->y] >= 1) ? 0 : PLAYER->dir_x * SPEED;
		PLAYER->y += (map->map_i[(int)PLAYER->x]
					[(int)(PLAYER->y + PLAYER->dir_y * SPEED)] == 1) ? 0 : PLAYER->dir_y * SPEED;
	}
	if (key_code == 1)
	{
		PLAYER->x -= (map->map_i[(int)(PLAYER->x - PLAYER->dir_x * SPEED)]
					[(int)PLAYER->y] >= 1) ? 0 : PLAYER->dir_x * SPEED;
		PLAYER->y -= (map->map_i[(int)PLAYER->x]
					[(int)(PLAYER->y - PLAYER->dir_y * SPEED)] == 1) ? 0 : PLAYER->dir_y * SPEED;
	}
	return (0);
}

int		movt_left_right(int key_code, t_map *map)
{
	if (key_code == 0)
	{
		PLAYER->x -= (map->map_i[(int)(PLAYER->x - PLAYER->dir_y * SPEED)]
					[(int)PLAYER->y] >= 1) ? 0 : PLAYER->dir_y * SPEED;
		PLAYER->y += (map->map_i[(int)PLAYER->x]
					[(int)(PLAYER->y + PLAYER->dir_x * SPEED)] == 1) ? 0 : PLAYER->dir_x * SPEED;
	}
	if (key_code == 2)
	{
		PLAYER->x += (map->map_i[(int)(PLAYER->x + PLAYER->dir_y * SPEED)]
					[(int)PLAYER->y] >= 1) ? 0 : PLAYER->dir_y * SPEED;
		PLAYER->y -= (map->map_i[(int)PLAYER->x]
					[(int)(PLAYER->y - PLAYER->dir_x * SPEED)] == 1) ? 0 : PLAYER->dir_x * SPEED;
	}
	return (0);
}

int		movt_rot_left_right(int key_code, t_map *map)
{
	double dir_x;
	double dir_y;
	double plane_x;
	double plane_y;

	dir_x = PLAYER->dir_x;
	dir_y = PLAYER->dir_y;
	plane_x = SCREEN->plane_x;
	plane_y = SCREEN->plane_y;
	if (key_code == 123)
	{
		PLAYER->dir_x = cos(ROTSPEED) * dir_x - sin(ROTSPEED) * dir_y;
		PLAYER->dir_y = sin(ROTSPEED) * dir_x + cos(ROTSPEED) * dir_y;
		SCREEN->plane_x = cos(ROTSPEED) * plane_x - sin(ROTSPEED) * plane_y;
		SCREEN->plane_y = sin(ROTSPEED) * plane_x + cos(ROTSPEED) * plane_y;
	}
	if (key_code == 124)
	{
		PLAYER->dir_x = cos(ROTSPEED) * dir_x + sin(ROTSPEED) * dir_y;
		PLAYER->dir_y = cos(ROTSPEED) * dir_y - sin(ROTSPEED) * dir_x;
		SCREEN->plane_x = cos(ROTSPEED) * plane_x + sin(ROTSPEED) * plane_y;
		SCREEN->plane_y = cos(ROTSPEED) * plane_y - sin(ROTSPEED) * plane_x;
	}
	return (0);
}

int	movt_do(t_map *map)
{
	(MOVT->front == 1) ? movt_front_back(13, map) : 0;
	(MOVT->back == 1) ? movt_front_back(1, map) : 0;
	(MOVT->left == 1) ? movt_left_right(0, map) : 0;
	(MOVT->right == 1) ? movt_left_right(2, map) : 0;
	(MOVT->rot_left == 1) ? movt_rot_left_right(123, map) : 0;
	(MOVT->rot_right == 1) ? movt_rot_left_right(124, map) : 0;
	raycasting(map);
	return (0);
}

int	movt_pressed(int key_code, t_map *map)
{
	if (key_code == 53)
		exit(0);
	(key_code == 13 || key_code == 126) ? MOVT->front = 1 : 0;
	(key_code == 1 || key_code == 125) ? MOVT->back = 1 : 0;
	(key_code == 0) ? MOVT->left = 1 : 0;
	(key_code == 2) ? MOVT->right = 1 : 0;
	(key_code == 123) ? MOVT->rot_left = 1 : 0;
	(key_code == 124) ? MOVT->rot_right = 1 : 0;
	movt_do(map);
	return (0);
}

int	movt_released(int key_code, t_map *map)
{
	(key_code == 13 || key_code == 126) ? MOVT->front = 0 : 0;
	(key_code == 1 || key_code == 125) ? MOVT->back = 0 : 0;
	(key_code == 0) ? MOVT->left = 0 : 0;
	(key_code == 2) ? MOVT->right = 0 : 0;
	(key_code == 123) ? MOVT->rot_left = 0 : 0;
	(key_code == 124) ? MOVT->rot_right = 0 : 0;
	movt_do(map);
	return (0);
}
