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

int	movt_do(t_map *m)
{
	(m->mo->front == 1) ? movt_front_back(13, m) : 0;
	(m->mo->back == 1) ? movt_front_back(1, m) : 0;
	(m->mo->left == 1) ? movt_left_right(0, m) : 0;
	(m->mo->right == 1) ? movt_left_right(2, m) : 0;
	(m->mo->rot_left == 1) ? rot_left_right(123, m) : 0;
	(m->mo->rot_right == 1) ? rot_left_right(124, m) : 0;
	raycasting(m);
	return (0);
}

int	movt_pressed(int key_code, t_map *m)
{
	if (key_code == 53)
		free_all(m, 2);
	(key_code == 13 || key_code == 126) ? m->mo->front = 1 : 0;
	(key_code == 1 || key_code == 125) ? m->mo->back = 1 : 0;
	(key_code == 0) ? m->mo->left = 1 : 0;
	(key_code == 2) ? m->mo->right = 1 : 0;
	(key_code == 123) ? m->mo->rot_left = 1 : 0;
	(key_code == 124) ? m->mo->rot_right = 1 : 0;
	movt_do(m);
	return (0);
}

int	movt_released(int key_code, t_map *m)
{
	(key_code == 13 || key_code == 126) ? m->mo->front = 0 : 0;
	(key_code == 1 || key_code == 125) ? m->mo->back = 0 : 0;
	(key_code == 0) ? m->mo->left = 0 : 0;
	(key_code == 2) ? m->mo->right = 0 : 0;
	(key_code == 123) ? m->mo->rot_left = 0 : 0;
	(key_code == 124) ? m->mo->rot_right = 0 : 0;
	movt_do(m);
	return (0);
}
