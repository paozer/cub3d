/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 22:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/13 01:51:00 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_mlx(t_map *m, int flag)
{
	int i;

	if (m->save == 0)
		mlx_destroy_window(m->mx->mlx_ptr, m->mx->win_ptr);
	(flag == 3) ? 0 : free(m->mo);
	i = 0;
	while (i < 5)
	{
		mlx_destroy_image(m->mx->mlx_ptr, m->t[i]->img);
		free(m->t[i]);
		++i;
	}
	mlx_destroy_image(m->mx->mlx_ptr, m->i->img);
	free(m->i);
	free(m->mx);
	free(m->sp->wall_dist);
	i = 0;
	while (m->sp->arr[i])
		free(m->sp->arr[i++]);
	free(m->sp->arr);
	free(m->sp);
}

int			free_dummy(t_map *m)
{
	free_all(m, 2);
	return (0);
}

void		free_all(t_map *m, int flag)
{
	int i;

	i = 0;
	if (flag != 0)
	{
		free(m->cc);
		free(m->fc);
		(flag == 1) ? free(m->sp) : 0;
		(flag == 1) ? free(m->mx) : 0;
		free(m->s);
		free(m->ra);
		free(m->p);
		free(m->re);
		while (i < 5)
			free(m->tp[i++]);
		i = 0;
		while (m->map && m->map[i])
			free(m->map[i++]);
		(m->map) ? free(m->map[i]) : 0;
		free(m->map);
	}
	(flag == 2 || flag == 3) ? free_mlx(m, flag) : 0;
	free(m);
	while (1) ;
	exit(0);
}
