/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_spri.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 21:45:59 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 19:59:14 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	sprites_draw(t_map *map)
{
	int i;
	int j;
	int y;
	double inv_deter;
	double trans_x;
	double trans_y;
	int spr_screen_x;
	int spr_height;
	int spr_width;
	int draw_start_y;
	int draw_end_y;
	int draw_start_x;
	int draw_end_x;
	int tex_x;
	int tex_y;

	double sprite_x;
	double sprite_y;


	i = 0;
	while (i < SPR->nbr)
	{
		sprite_x = SPR->arr[i]->x - PLAYER->x;
		sprite_y = SPR->arr[i]->y - PLAYER->y;

		inv_deter = 1.0 / (SCREEN->plane_x * PLAYER->dir_y - PLAYER->dir_x * SCREEN->plane_y);

		trans_x = inv_deter * (PLAYER->dir_y * sprite_x - PLAYER->dir_x * sprite_y);
		trans_y = inv_deter * (-SCREEN->plane_y * sprite_x + SCREEN->plane_x * sprite_y);

		spr_screen_x = (int)((RES->x / 2) * (1 + trans_x / trans_y));

		spr_height = abs((int)(RES->y / trans_y));
		draw_start_y = -spr_height / 2 + RES->y / 2;
		(draw_start_y < 0) ? draw_start_y = 0 : 0;
		draw_end_y = spr_height / 2 + RES->y / 2;
		(draw_end_y >= RES->y) ? draw_end_y = RES->y - 1 : 0;

		spr_width = abs((int)(RES->y / trans_y));
		draw_start_x = -spr_width / 2 + spr_screen_x;
		(draw_start_x < 0) ? draw_start_x = 0 : 0;
		draw_end_x = spr_width / 2 + spr_screen_x;
		(draw_end_x >= RES->x) ? draw_end_x = RES->x - 1 : 0;

		j = draw_start_x;
		while (j < draw_end_x)
		{
			tex_x = (int)(256 * (j - (-spr_width / 2 + spr_screen_x)) * TEXT[4]->width / spr_width) / 256;
			if (trans_y > 0 && j > 0 && j < RES->x && trans_y < *SPR->wall_dist[j])
			{
				y = draw_start_y;
				while (y < draw_end_y)
				{
					int d = y * 256 - RES->y * 128 + spr_height * 128;
					tex_y = ((d * TEXT[4]->height) / spr_height) / 256;
					int color = TEXT[4]->buf[tex_y * TEXT[4]->width + tex_x];
					if ((color & 0x00ffffff) != 0)
						IMG->buf[y * RES->x + j] = color;
					++y;
				}
			}
			++j;
		}
		++i;
	}
}

void	sprites_sort(t_map *map)
{
	int i;
	t_spr *tmp;

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
