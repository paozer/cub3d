/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_movt.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/15 16:13:03 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 17:42:30 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int		movt_front_back(int key_code, t_map *map)
{
	if (key_code == 13)
	{
		PLAYER->x += PLAYER->dir_x * SPEED;
		PLAYER->y += PLAYER->dir_y * SPEED;
	}
	if (key_code == 1)
	{
		PLAYER->x -= PLAYER->dir_x * SPEED;
		PLAYER->y -= PLAYER->dir_y * SPEED;
	}
	return (0);
}

int	movt_do(t_map *map)
{
	(MOVT->front == 1) ? movt_front_back(13, map) : 0;
	(MOVT->back == 1) ? movt_front_back(1, map) : 0;
	/*
	(MOVT->left == 1) ? movt_left_right(13, map) : 0;
	(MOVT->right == 1) ? movt_left_right(13, map) : 0;
	(MOVT->rot_left == 1) ? movt_front_back(13, map) : 0;
	(MOVT->rot_right == 1) ? movt_front_back(13, map) : 0;
	*/
	ft_raycasting(map);
	return (0);
}

int	movt_pressed(int key_code, t_map *map)
{
	(key_code == 13) ? MOVT->front = 1 : 0;
	(key_code == 1) ? MOVT->back = 1 : 0;
	(key_code == 0) ? MOVT->left = 1 : 0;
	(key_code == 2) ? MOVT->right = 1 : 0;
	//(key_code == ) ? MOVT->rot_left = 1 : 0;
	//(key_code == ) ? MOVT->rot_right = 1 : 0;
	movt_do(map);
	return (0);
}

int	movt_released(int key_code, t_map *map)
{
	(key_code == 13) ? MOVT->front = 0 : 0;
	(key_code == 1) ? MOVT->back = 0 : 0;
	(key_code == 0) ? MOVT->left = 0 : 0;
	(key_code == 2) ? MOVT->right = 0 : 0;
	//(key_code == ) ? MOVT->rot_left = 0 : 0;
	//(key_code == ) ? MOVT->rot_right = 0 : 0;
	movt_do(map);
	return (0);
}
