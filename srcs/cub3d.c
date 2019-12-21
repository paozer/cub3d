/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/21 17:10:59 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_sprites(t_map *map)
{
	int i;
	int j;
	int y;

	if (!(SPR->arr = malloc(sizeof(t_spr) * (SPR->nbr + 1))))
		return ;
	SPR->arr[SPR->nbr] = NULL;
	i = 0;
	y = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (j < map->map_width)
		{
			if (map->map_i[i][j] == 2)
			{
				if (!(SPR->arr[y] = malloc(sizeof(*SPR->arr[y]))))
					return ;
				SPR->arr[y]->x = i + .5;
				SPR->arr[y]->y = j + .5;
				++y;
			}
			++j;
		}
		++i;
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

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
	{
		ft_printf("Error\nUsage: ./cube3d path/to/map.cub\n");
		return (0);
	}
	map = parsing(argv[1]);
	init(map);
	init_sprites(map);
	start(map);
	return (0);
}
