/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 21:06:58 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	(void)argc;

	/* add argc check with appropriate error message */
	map = ft_parsing(argv[1]);
	if ((MLX->mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((MLX->wd_ptr = mlx_new_window(MLX->mlx_ptr, map->res_ptr->x, map->res_ptr->y, "cube3d")) == NULL)
		return (0);
	if (!(map->img = malloc(sizeof(*(map->img)))))
		return (0);
	IMG->img = mlx_new_image(MLX->mlx_ptr, RES->x, RES->y);
	IMG->buf = (int *)mlx_get_data_addr(IMG->img, &IMG->bpp, &IMG->size_line, &IMG->endian);
	ft_raycasting(map);
	mlx_loop(MLX->mlx_ptr);
	return (0);
}
