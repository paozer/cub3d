/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_draw.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 19:46:05 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void		draw(t_map *map, int x)
{
	int		y;
	int		draw_start;
	int		draw_end;

	y = 0;
	draw_start = (RES->y - RAY->line_h) / 2;
	draw_end = (RES->y + RAY->line_h) / 2;
	draw_start = (draw_start > 0) ? draw_start : 0;
	draw_end = (draw_end >= RES->y) ? RES->y - 1 : draw_end;
	printf("start = %d end = %d line = %d\n", draw_start, draw_end, RAY->line_h);
	while (y < map->res_ptr->y)
	{
		if ( y < draw_start)
		{
			// print ceiling
			IMG->buf[y * RES->x + x] = 0x8814f5;
		}
		if (y >= draw_start && y < draw_end)
		{
			// print wall
			IMG->buf[y * RES->x + x] = 0xfa8080;
		}
		if (y >= draw_end)
		{
			// print floor
			IMG->buf[y * RES->x + x] = 0x0;
		}
		++y;
	}
}
