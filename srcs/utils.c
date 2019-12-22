/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 22:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 03:44:00 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		free_dummy(t_map *map)
{
	free_all(map, 2);
	return (0);
}

void	free_all(t_map *map, int flag)
{
	int i;

	i = 0;
	if (flag != 0)
	{
		free_extra(map, flag);
		while (i < 5)
			free(TEXT_P[i++]);
		i = 0;
		while (map->map[i])
			free(map->map[i++]);
		free(map->map[i]);
		free(map->map);
		i = 0;
		while (i < map->height)
			free(map->map_i[i++]);
		free(map->map_i);
	}
	(flag == 2) ? free_mlx(map) : 0;
	free(map);
	while (1) ;
	exit(0);
}

void	free_extra(t_map *map, int flag)
{
	free(CEI_CLR);
	free(FLO_CLR);
	(flag == 1) ? free(SPR) : 0;
	(flag == 1) ? free(MLX) : 0;
	free(SCREEN);
	free(RAY);
	free(PLAYER);
	free(RES);
}

void	free_mlx(t_map *map)
{
	int i;

	i = 0;
	mlx_destroy_window(MLX->mlx_ptr, MLX->win_ptr);
	free(MLX);
	free(MOVT);
	while (i < 5)
	{
		free(TEXT[i]->img);
		free(TEXT[i]->buf);
		free(TEXT[i++]);
	}
	i = 0;
	free(SPR->wall_dist);
	i = 0;
	while (SPR->arr[i])
		free(SPR->arr[i++]);
	free(SPR->arr);
	free(SPR);
	free(IMG->img);
	free(IMG->buf);
	free(IMG);
}
