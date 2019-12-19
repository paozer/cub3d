/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_draw.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/19 19:55:35 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

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

void		select_pixel(t_map *map, int i, int x, int y)
{
	int		d;
	int		tex_x;
	int		tex_y;
	int		color;
	double	wall_x;
	int		draw_end;

	draw_end = (RES->y + RAY->line_h) / 2;
	draw_end = (draw_end >= RES->y) ? RES->y - 1 : draw_end;

	wall_x = (RAY->side) ? PLAYER->x + RAY->wall_dist * RAY->dir_x :
			PLAYER->y + RAY->wall_dist * RAY->dir_y;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * (double)TEXT[i]->width);
	((RAY->side == 0 && RAY->dir_x > 0) || (RAY->side == 1 && RAY->dir_y < 0)) ?
			tex_x = TEXT[i]->width - tex_x - 1 : 0;
	while (y < draw_end)
	{
		d = y * 256 - RES->y * 128 + RAY->line_h * 128;
		tex_y = d * TEXT[i]->height / RAY->line_h / 256;
		tex_y < 0 ? tex_y = 0 : 0;
		if (TEXT[i]->height * TEXT[i]->width > tex_y * TEXT[i]->width + tex_x)
		{
			color = TEXT[i]->buf[tex_y * TEXT[i]->width + tex_x];
			IMG->buf[y * RES->x + x] = color;
		}
		y++;
	}
}

void		draw(t_map *map, int x)
{
	int		y;
	int		text_index;
	int		draw_start;
	int		draw_end;

	y = 0;
	draw_start = (RES->y - RAY->line_h) / 2;
	draw_end = (RES->y + RAY->line_h) / 2;
	draw_start = (draw_start > 0) ? draw_start : 0;
	draw_end = (draw_end >= RES->y) ? RES->y - 1 : draw_end;
	text_index = select_texture(map);
	while (y < RES->y)
	{
		if (y < draw_start)
			IMG->buf[y * RES->x + x] = *map->cei_clr;
		if (y >= draw_start && y < draw_end)
		{
			select_pixel(map, text_index, x, y);
			y = draw_end;
		}
		if (y >= draw_end)
			IMG->buf[y * RES->x + x] = *map->flo_clr;
		++y;
	}
}
