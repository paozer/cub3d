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

#include "../cub3d.h"

void	sprites_select_pixel(t_map *map, int j)
{
	int y;
	int d;
	int color;

	if (SPR->trans_y > 0 && j > 0 && j < RES->x &&
			SPR->trans_y < SPR->wall_dist[j])
	{
		y = SPR->draw_start_y;
		while (y < SPR->draw_end_y)
		{
			d = y * 256 - RES->y * 128 + SPR->height * 128;
			SPR->tex_y = ((d * TEXT[4]->width) / SPR->height) / 256;
			if (TEXT[4]->width * TEXT[4]->height > SPR->tex_y * TEXT[4]->width +
					SPR->tex_x)
			{
				color = TEXT[4]->buf[SPR->tex_y * TEXT[4]->width + SPR->tex_x];
				if (color != 0)
					IMG->buf[y * RES->x + j] = color;
			}
			++y;
		}
	}
}

void	sprites_start_end(t_map *map)
{
	SPR->height = abs((int)(RES->y / SPR->trans_y));
	SPR->draw_start_y = -SPR->height / 2 + RES->y / 2;
	(SPR->draw_start_y < 0) ? SPR->draw_start_y = 0 : 0;
	SPR->draw_end_y = SPR->height / 2 + RES->y / 2;
	(SPR->draw_end_y >= RES->y) ? SPR->draw_end_y = RES->y - 1 : 0;
	SPR->width = abs((int)(RES->y / SPR->trans_y));
	SPR->draw_start_x = -SPR->width / 2 + SPR->screen_x;
	(SPR->draw_start_x < 0) ? SPR->draw_start_x = 0 : 0;
	SPR->draw_end_x = SPR->width / 2 + SPR->screen_x;
	(SPR->draw_end_x >= RES->x) ? SPR->draw_end_x = RES->x - 1 : 0;
}

void	sprites_draw(t_map *map)
{
	int i;
	int j;

	i = 0;
	while (i < SPR->nbr)
	{
		SPR->x = SPR->arr[i]->x - PLAYER->x;
		SPR->y = SPR->arr[i]->y - PLAYER->y;
		SPR->inv_deter = 1.0 / (SCREEN->plane_x * PLAYER->dir_y -
				PLAYER->dir_x * SCREEN->plane_y);
		SPR->trans_x = SPR->inv_deter *
			(PLAYER->dir_y * SPR->x - PLAYER->dir_x * SPR->y);
		SPR->trans_y = SPR->inv_deter *
			(-SCREEN->plane_y * SPR->x + SCREEN->plane_x * SPR->y);
		SPR->screen_x = (int)((RES->x / 2) * (1 + SPR->trans_x / SPR->trans_y));
		sprites_start_end(map);
		j = SPR->draw_start_x;
		while (j < SPR->draw_end_x)
		{
			SPR->tex_x = (int)(256 * (j - (-SPR->width / 2 + SPR->screen_x))
					* TEXT[4]->height / SPR->width) / 256;
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
	while (SPR->arr[i] && SPR->arr[i + 1])
	{
		if (SPR->arr[i]->dist < SPR->arr[i + 1]->dist)
		{
			tmp = SPR->arr[i + 1];
			SPR->arr[i + 1] = SPR->arr[i];
			SPR->arr[i] = tmp;
			i = 0;
		}
		++i;
	}
}

void	sprites_main(t_map *map)
{
	int i;

	i = 0;
	while (SPR->arr[i])
	{
		SPR->arr[i]->dist = pow(PLAYER->x - SPR->arr[i]->x, 2)
			+ pow(PLAYER->y - SPR->arr[i]->y, 2);
		++i;
	}
	sprites_sort(map);
	sprites_draw(map);
}
