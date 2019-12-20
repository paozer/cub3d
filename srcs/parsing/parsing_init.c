/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 18:32:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 23:26:56 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void		init_res(t_map *map)
{
	if (!(RES = malloc(sizeof(*RES))))
		return ;
	RES->x = -1;
	RES->y = -1;
}

void		init_player(t_map *map)
{
	if (!(PLAYER = malloc(sizeof(*PLAYER))))
		return ;
	PLAYER->set_flag = 0;
	PLAYER->x = 0;
	PLAYER->y = 0;
	PLAYER->dir_x = 0;
	PLAYER->dir_y = 0;
}

void		init_ray(t_map *map)
{
	if (!(RAY = malloc(sizeof(*RAY))))
		return ;
	RAY->x = 0;
	RAY->y = 0;
	RAY->dir_x = 0;
	RAY->dir_y = 0;
	RAY->map_x = 0;
	RAY->map_y = 0;
	RAY->side_dist_x = 0;
	RAY->side_dist_y = 0;
	RAY->delta_dist_x = 0;
	RAY->delta_dist_y = 0;
	RAY->step_x = 0;
	RAY->step_y = 0;
	RAY->side = 0;
	RAY->hit = 0;
	RAY->wall_dist = 0;
}

void		init_screen(t_map *map)
{
	if (!(SCREEN = malloc(sizeof(*SCREEN))))
		return ;
	SCREEN->plane_x = 0;
	SCREEN->plane_y = 0;
	SCREEN->cam_x = 0;
	SCREEN->cam_y = 0;
}

void	init_sprites(t_map *map)
{
	if (!(SPR = malloc(sizeof(*SPR))))
		return ;
	if (!(SPR->img = malloc(sizeof(*SPR->img))))
		return ;
	if (!(SPR->lst = malloc(sizeof(*SPR->lst))))
		return ;
	SPR->lst = NULL;
}

t_map		*init_map(void)
{
	t_map	*map;
	t_mlx	*ptr;

	if (!(map = malloc(sizeof(*map))))
		return (NULL);
	map->map = NULL;
	if (!(ptr = malloc(sizeof(*ptr))))
		return (NULL);
	MLX = ptr;
	init_ray(map);
	init_screen(map);
	init_player(map);
	init_res(map);
	init_sprites(map);
	if (!(map->flo_clr = malloc(sizeof(*map->flo_clr))))
		return (NULL);
	if (!(map->cei_clr = malloc(sizeof(*map->cei_clr))))
		return (NULL);
	return (map);
}
