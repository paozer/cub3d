/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 00:03:56 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

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
						&TEXT[i]->height, &TEXT[i]->width);
		TEXT[i]->buf = (int *)mlx_get_data_addr(TEXT[i]->img, &TEXT[i]->bpp,
						&TEXT[i]->size_line, &TEXT[i]->endian);
		++i;
	}
	/* sprites initialisation requiring results frim parsing */
	if (!(SPR->wall_dist = malloc(sizeof(*SPR->wall_dist) * RES->x)))
		return ;
	SPR->img = mlx_xpm_file_to_image(MLX->mlx_ptr, TEXT_P[4],
		&SPR->img->height, &SPR->img->width);
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
	start(map);
	return (0);
}
