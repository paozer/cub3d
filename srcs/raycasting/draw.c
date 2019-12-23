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
	(RAY->side == 0 && RAY->dir_x > 0) ? (i = 0) : 0;
	(RAY->side == 0 && RAY->dir_x < 0) ? (i = 1) : 0;
	(RAY->side == 1 && RAY->dir_y < 0) ? (i = 2) : 0;
	(RAY->side == 1 && RAY->dir_y > 0) ? (i = 3) : 0;
	return (i);
}

void		select_pixel_while(t_map *map, int x, int y, int i)
{
	int d;
	int color;

	while (y < IMG->draw_end)
	{
		d = y * 256 - RES->y * 128 + RAY->line_h * 128;
		IMG->tex_y = d * TEXT[i]->height / RAY->line_h / 256;
		IMG->tex_y < 0 ? IMG->tex_y = 0 : 0;
		if (TEXT[i]->height * TEXT[i]->width >
				IMG->tex_y * TEXT[i]->height + IMG->tex_x)
		{
			color = TEXT[i]->buf[IMG->tex_y * TEXT[i]->height + IMG->tex_x];
			IMG->buf[y * RES->x + x] = color;
		}
		y++;
	}
}

void		select_pixel(t_map *map, int i, int x, int y)
{
	IMG->wall_x = (RAY->side) ? PLAYER->x + RAY->wall_dist * RAY->dir_x :
		PLAYER->y + RAY->wall_dist * RAY->dir_y;
	IMG->wall_x -= floor(IMG->wall_x);
	IMG->tex_x = (int)(IMG->wall_x * (double)TEXT[i]->width);
	((RAY->side == 0 && RAY->dir_x > 0) || (RAY->side == 1 && RAY->dir_y < 0)) ?
		IMG->tex_x = TEXT[i]->width - IMG->tex_x - 1 : 0;
	select_pixel_while(map, x, y, i);
}

void		draw(t_map *map, int x)
{
	int		y;
	int		text_index;

	y = 0;
	IMG->draw_start = (RES->y - RAY->line_h) / 2;
	IMG->draw_end = (RES->y + RAY->line_h) / 2;
	IMG->draw_start = (IMG->draw_start > 0) ? IMG->draw_start : 0;
	IMG->draw_end = (IMG->draw_end >= RES->y) ? RES->y - 1 : IMG->draw_end;
	text_index = select_texture(map);
	while (y < RES->y)
	{
		if (y < IMG->draw_start)
			IMG->buf[y * RES->x + x] = *map->cei_clr;
		if (y >= IMG->draw_start && y < IMG->draw_end)
		{
			select_pixel(map, text_index, x, y);
			y = IMG->draw_end;
		}
		if (y >= IMG->draw_end)
			IMG->buf[y * RES->x + x] = *map->flo_clr;
		++y;
	}
}
