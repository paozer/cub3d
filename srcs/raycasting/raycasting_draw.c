/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_draw.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 15:49:32 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int			select_texture(t_map *map)
{
	int i;

	i = 0;
	(RAY->side == 0 && RAY->dir_x > 0) ? (i = 0) : 0; // N
	(RAY->side == 0 && RAY->dir_x < 0) ? (i = 1) : 0; // S
	(RAY->side == 1 && RAY->dir_y < 0) ? (i = 2) : 0; // E
	(RAY->side == 1 && RAY->dir_y > 0) ? (i = 3) : 0; // W
	return (i);
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
	while (y < map->res_ptr->y)
	{
		if (y < draw_start)
			IMG->buf[y * RES->x + x] = FLOOR->clr;
		if (y >= draw_start && y < draw_end)
			IMG->buf[y * RES->x + x] = 0xfa8080;
//			IMG->buf[y * RES->x + x] = select_pixel(map, text_index, x, y)
		if (y >= draw_end)
			IMG->buf[y * RES->x + x] = CEILING->clr;
		++y;
	}
}
