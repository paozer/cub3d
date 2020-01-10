/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   draw.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 08:31:44 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int			select_texture(t_map *map)
{
	int i;

	i = 0;
	(map->ra->side == 0 && map->ra->dir_x > 0) ? (i = 0) : 0;
	(map->ra->side == 0 && map->ra->dir_x < 0) ? (i = 1) : 0;
	(map->ra->side == 1 && map->ra->dir_y < 0) ? (i = 2) : 0;
	(map->ra->side == 1 && map->ra->dir_y > 0) ? (i = 3) : 0;
	return (i);
}

void		select_pixel_while(t_map *map, int x, int y, int i)
{
	int d;
	int color;

	while (y < map->i->draw_end)
	{
		d = y * 256 - map->re->y * 128 + map->ra->line_h * 128;
		map->i->tex_y = d * map->t[i]->height / map->ra->line_h / 256;
		map->i->tex_y < 0 ? map->i->tex_y = 0 : 0;
		if (map->t[i]->height * map->t[i]->width >
				map->i->tex_y * map->t[i]->height + map->i->tex_x)
		{
			color = map->t[i]->buf[map->i->tex_y * map->t[i]->height + map->i->tex_x];
			map->i->buf[y * map->re->x + x] = color;
		}
		y++;
	}
}

void		select_pixel(t_map *map, int i, int x, int y)
{
	map->i->wall_x = (map->ra->side) ? map->p->x + map->ra->wall_dist * map->ra->dir_x :
		map->p->y + map->ra->wall_dist * map->ra->dir_y;
	map->i->wall_x -= floor(map->i->wall_x);
	map->i->tex_x = (int)(map->i->wall_x * (double)map->t[i]->width);
	((map->ra->side == 0 && map->ra->dir_x > 0) || (map->ra->side == 1 && map->ra->dir_y < 0)) ?
		map->i->tex_x = map->t[i]->width - map->i->tex_x - 1 : 0;
	select_pixel_while(map, x, y, i);
}

void		draw(t_map *map, int x)
{
	int		y;
	int		text_index;

	y = 0;
	map->i->draw_start = (map->re->y - map->ra->line_h) / 2;
	map->i->draw_end = (map->re->y + map->ra->line_h) / 2;
	map->i->draw_start = (map->i->draw_start > 0) ? map->i->draw_start : 0;
	map->i->draw_end = (map->i->draw_end >= map->re->y) ? map->re->y - 1 : map->i->draw_end;
	text_index = select_texture(map);
	while (y < map->re->y)
	{
		if (y < map->i->draw_start)
			map->i->buf[y * map->re->x + x] = *map->cc;
		if (y >= map->i->draw_start && y < map->i->draw_end)
		{
			select_pixel(map, text_index, x, y);
			y = map->i->draw_end;
		}
		if (y >= map->i->draw_end)
			map->i->buf[y * map->re->x + x] = *map->fc;
		++y;
	}
}
