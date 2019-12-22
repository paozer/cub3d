/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 18:32:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 03:49:55 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(*map))))
		print_error(8, NULL, NULL, 0);
	FLO_CLR = malloc(sizeof(*FLO_CLR));
	CEI_CLR = malloc(sizeof(*CEI_CLR));
	MLX = malloc(sizeof(*MLX));
	RES = malloc(sizeof(*RES));
	SCREEN = malloc(sizeof(*SCREEN));
	PLAYER = malloc(sizeof(*PLAYER));
	(PLAYER) ? PLAYER->set_flag = 0 : 0;
	RAY = malloc(sizeof(*RAY));
	SPR = malloc(sizeof(*SPR));
	if (!(map && ALL))
		print_error(8, NULL, map, 1);
	return (map);
}

void	init_sprites(t_map *map)
{
	int i;
	int j;
	int y;

	if (!(SPR->arr = malloc(sizeof(t_spr) * (SPR->nbr + 1))))
		return ;
	SPR->arr[SPR->nbr] = NULL;
	i = -1;
	y = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_i[i][j] == 2)
			{
				if (!(SPR->arr[y] = malloc(sizeof(*SPR->arr[y]))))
					return ;
				SPR->arr[y]->x = i + .5;
				SPR->arr[y++]->y = j + .5;
			}
		}
	}
	if (!(SPR->wall_dist = malloc(sizeof(*SPR->wall_dist) * RES->x)))
		return ;
}

void	init(t_map *map)
{
	int i;

	i = 0;
	if ((MLX->mlx_ptr = mlx_init()) == NULL)
		return ;
	if ((MLX->win_ptr = mlx_new_window(MLX->mlx_ptr, RES->x, RES->y,
					"cube3d")) == NULL)
		return ;
	if (!(map->img = malloc(sizeof(*(map->img)))))
		return ;
	IMG->img = mlx_new_image(MLX->mlx_ptr, RES->x, RES->y);
	IMG->buf = (int *)mlx_get_data_addr(IMG->img, &IMG->bpp,
			&IMG->size_line, &IMG->endian);
	while (i < 5)
	{
		if (!(TEXT[i] = malloc(sizeof(t_img))))
			return ;
		TEXT[i]->img = mlx_xpm_file_to_image(MLX->mlx_ptr, TEXT_P[i],
				&TEXT[i]->width, &TEXT[i]->height);
		TEXT[i]->buf = (int *)mlx_get_data_addr(TEXT[i]->img, &TEXT[i]->bpp,
				&TEXT[i]->size_line, &TEXT[i]->endian);
		++i;
	}
}
