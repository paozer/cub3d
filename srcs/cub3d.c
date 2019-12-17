/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/17 18:18:43 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	init_text(t_map *map)
{
	int i;

	i = 0;
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
}

void	init(t_map *map)
{
	if ((MLX->mlx_ptr = mlx_init()) == NULL)
		return ;
	if ((MLX->win_ptr = mlx_new_window(MLX->mlx_ptr, map->res_ptr->x,
					map->res_ptr->y, "cube3d")) == NULL)
		return ;
	if (!(map->img = malloc(sizeof(*(map->img)))))
		return ;
	IMG->img = mlx_new_image(MLX->mlx_ptr, RES->x, RES->y);
	IMG->buf = (int *)mlx_get_data_addr(IMG->img, &IMG->bpp,
					&IMG->size_line, &IMG->endian);
	init_text(map);
}

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
	{
		ft_printf("Error\nUsage: ./cube3d path/to/map.cub\n");
		return (0);
	}
	map = ft_parsing(argv[1]);
	init(map);
	start(map);
	return (0);
}
