/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_spri.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 21:45:59 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 00:20:41 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	sprites_select_pixel(t_map *map, int j)
{
	int y;
	int d;
	int color;

	if (map->sp->trans_y > 0 && j > 0 && j < map->re->x &&
			map->sp->trans_y < map->sp->wall_dist[j])
	{
		y = map->sp->draw_start_y;
		while (y < map->sp->draw_end_y)
		{
			d = y * 256 - map->re->y * 128 + map->sp->height * 128;
			map->sp->tex_y = ((d * map->t[4]->width) / map->sp->height) / 256;
			if (map->t[4]->width * map->t[4]->height > map->sp->tex_y * map->t[4]->width +
					map->sp->tex_x)
			{
				color = map->t[4]->buf[map->sp->tex_y * map->t[4]->width + map->sp->tex_x];
				if (color != 0)
					map->i->buf[y * map->re->x + j] = color;
			}
			++y;
		}
	}
}

void	sprites_start_end(t_map *map)
{
	map->sp->height = abs((int)(map->re->y / map->sp->trans_y));
	map->sp->draw_start_y = -map->sp->height / 2 + map->re->y / 2;
	(map->sp->draw_start_y < 0) ? map->sp->draw_start_y = 0 : 0;
	map->sp->draw_end_y = map->sp->height / 2 + map->re->y / 2;
	(map->sp->draw_end_y >= map->re->y) ? map->sp->draw_end_y = map->re->y - 1 : 0;
	map->sp->width = abs((int)(map->re->y / map->sp->trans_y));
	map->sp->draw_start_x = -map->sp->width / 2 + map->sp->screen_x;
	(map->sp->draw_start_x < 0) ? map->sp->draw_start_x = 0 : 0;
	map->sp->draw_end_x = map->sp->width / 2 + map->sp->screen_x;
	(map->sp->draw_end_x >= map->re->x) ? map->sp->draw_end_x = map->re->x - 1 : 0;
}

void	sprites_draw(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < map->sp->nbr)
	{
		map->sp->x = map->sp->arr[i]->x - map->p->x;
		map->sp->y = map->sp->arr[i]->y - map->p->y;
		map->sp->inv_deter = 1.0 / (map->s->plane_x * map->p->dir_y -
				map->p->dir_x * map->s->plane_y);
		map->sp->trans_x = map->sp->inv_deter *
			(map->p->dir_y * map->sp->x - map->p->dir_x * map->sp->y);
		map->sp->trans_y = map->sp->inv_deter *
			(-map->s->plane_y * map->sp->x + map->s->plane_x * map->sp->y);
		map->sp->screen_x = (int)((map->re->x / 2) * (1 + map->sp->trans_x / map->sp->trans_y));
		sprites_start_end(map);
		j = map->sp->draw_start_x;
		while (j < map->sp->draw_end_x)
		{
			map->sp->tex_x = (int)(256 * (j - (-map->sp->width / 2 + map->sp->screen_x))
					* map->t[4]->height / map->sp->width) / 256;
			sprites_select_pixel(map, j++);
		}
		++i;
	}
}

void	sprites_sort(t_map *map)
{
	int		i;
	t_spr	*tmp;

	i = 0;
	while (map->sp->arr[i] && map->sp->arr[i + 1])
	{
		if (map->sp->arr[i]->dist < map->sp->arr[i + 1]->dist)
		{
			tmp = map->sp->arr[i + 1];
			map->sp->arr[i + 1] = map->sp->arr[i];
			map->sp->arr[i] = tmp;
			i = 0;
		}
		++i;
	}
}

void	sprites_main(t_map *map)
{
	int i;

	i = 0;
	while (map->sp->arr[i])
	{
		map->sp->arr[i]->dist = pow(map->p->x - map->sp->arr[i]->x, 2)
			+ pow(map->p->y - map->sp->arr[i]->y, 2);
		++i;
	}
	sprites_sort(map);
	sprites_draw(map);
}
