/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_draw.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 17:01:45 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

int			select_texture(t_map *map, int x, int y)
{
	(void)map;
	(void)x;
	(void)y;
	return (0xfa8080);
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
	text_index = select_texture(map, x, y);
	while (y < map->res_ptr->y)
	{
		if (y < draw_start)
			IMG->buf[y * RES->x + x] = FLOOR->clr;
		if (y >= draw_start && y < draw_end)
			IMG->buf[y * RES->x + x] = 0xfa8080;
		if (y >= draw_end)
			IMG->buf[y * RES->x + x] = CEILING->clr;
		++y;
	}
}
