/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_draw.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/16 14:17:11 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

/*
int			select_texture(t_map *map, int y)
{

}
*/

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
	while (y < map->res_ptr->y)
	{
		if ( y < draw_start)
			IMG->buf[y * RES->x + x] =
					((CEILING->red<<16)|(CEILING->green<<8)|(CEILING->blue));
		if (y >= draw_start && y < draw_end)
		{
			// print wall
			IMG->buf[y * RES->x + x] = 0xfa8080;
		}
		if (y >= draw_end)
			IMG->buf[y * RES->x + x] =
					((FLOOR->red<<16)|(FLOOR->green<<8)|(FLOOR->blue));
		++y;
	}
}
