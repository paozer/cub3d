/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 22:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/27 13:21:35 by paozer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_extra(t_map *map, int flag)
{
	free(map->cc);
	free(map->fc);
	(flag == 1) ? free(map->sp) : 0;
	(flag == 1) ? free(map->mx) : 0;
	free(map->s);
	free(map->ra);
	free(map->p);
	free(map->re);
}

static void	free_mlx(t_map *map, int flag)
{
	int i;

	i = 0;
	mlx_destroy_window(map->mx->mlx_ptr, map->mx->win_ptr);
	free(map->mx);
	(flag == 3) ? 0 : free(map->mo);
	while (i < 5)
	{
		free(map->t[i]->img);
		free(map->t[i]->buf);
		free(map->t[i++]);
	}
	i = 0;
	free(map->sp->wall_dist);
	i = 0;
	while (map->sp->arr[i])
		free(map->sp->arr[i++]);
	free(map->sp->arr);
	free(map->sp);
	free(map->i->img);
	free(map->i->buf);
	free(map->i);
}

int			free_dummy(t_map *map)
{
	free_all(map, 2);
	return (0);
}

void		free_all(t_map *map, int flag)
{
	int i;

	i = 0;
	if (flag != 0)
	{
		free_extra(map, flag);
		while (i < 5)
			free(map->tp[i++]);
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
	(flag == 2 || flag == 3) ? free_mlx(map, flag) : 0;
	free(map);
	exit(0);
}
