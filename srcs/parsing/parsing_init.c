/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 18:32:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 22:53:50 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_init_res(t_map *map)
{
	if (!(RES = malloc(sizeof(*RES))))
		return ;
	RES->x = -1;
	RES->y = -1;
}

void		ft_init_textures(t_map *map)
{
	if (!(TEXT = malloc(sizeof(*TEXT))))
		return ;
	TEXT->north = NULL;
	TEXT->south = NULL;
	TEXT->west = NULL;
	TEXT->east = NULL;
	TEXT->sprite = NULL;
}

void		ft_init_color(t_color *ptr)
{
	if (!(ptr = malloc(sizeof(*ptr))))
		return ;
	ptr->red = -1;
	ptr->green = -1;
	ptr->blue = -1;
}


void			ft_init_player(t_map *map)
{
	if (!(PLAYER = malloc(sizeof(*PLAYER))))
		return ;
	PLAYER->set_flag = 0;
	PLAYER->x = 0;
	PLAYER->y = 0;
	PLAYER->dir_x = 0;
	PLAYER->dir_y = 0;
}

void				ft_init_ray(t_map *map)
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

void				ft_init_screen(t_map *map)
{
	if (!(SCREEN = malloc(sizeof(*SCREEN))))
		return ;
	SCREEN->plane_x = 0;
	SCREEN->plane_y = 0;
	SCREEN->cam_x = 0;
	SCREEN->cam_y = 0;
}

t_map				*ft_init_map(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(*map))))
		return (NULL);
	map->map = NULL;
	ft_init_ray(map);
	ft_init_screen(map);
	ft_init_player(map);
	ft_init_res(map);
	ft_init_textures(map);
	ft_init_color(map->floor_ptr);
	ft_init_color(map->ceiling_ptr);
	return (map);
}
