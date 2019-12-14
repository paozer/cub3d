/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 18:26:11 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map	*map;
	(void)argc;

	/* add argc check with appropriate error message */
	if ((MLX->mlx_ptr = mlx_init()) == NULL)
		return (0);
	map = ft_parsing(argv[1]);
	if ((MLX->wd_ptr = mlx_new_window(mlx_ptr, map->res_ptr->x, map->res_ptr->y, "cube3d")) == NULL)
		return (0);
	ft_raycasting(map);
	mlx_loop(mlx_ptr);
	return (0);
}
