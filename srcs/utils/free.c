/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 22:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 06:57:06 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void	free_extra(t_map *m, int flag)
{
	free(m->cc);
	free(m->fc);
	(flag == 1) ? free(m->sp) : 0;
	(flag == 1) ? free(m->mx) : 0;
	free(m->s);
	free(m->ra);
	free(m->p);
	free(m->re);
}

static void	free_mlx(t_map *m, int flag)
{
	int i;

	i = 0;
	if (m->save == 0)
		mlx_destroy_window(m->mx->mlx_ptr, m->mx->win_ptr);
	free(m->mx);
	(flag == 3) ? 0 : free(m->mo);
	while (i < 5)
	{
		free(m->t[i]->img);
		free(m->t[i]->buf);
		free(m->t[i++]);
	}
	i = 0;
	free(m->sp->wall_dist);
	i = 0;
	while (m->sp->arr[i])
		free(m->sp->arr[i++]);
	free(m->sp->arr);
	free(m->sp);
	free(m->i->img);
	free(m->i->buf);
	free(m->i);
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
		free_extra(m, flag);
		while (i < 5)
			free(m->tp[i++]);
		i = 0;
		while (m->map && m->map[i])
			free(m->map[i++]);
		(m->map) ? free(m->map[i]) : 0;
		free(m->map);
		i = 0;
		while (i < m->height)
			free(m->map_i[i++]);
		free(m->map_i);
	}
	(flag == 2 || flag == 3) ? free_mlx(m, flag) : 0;
	free(m);
	exit(0);
}
