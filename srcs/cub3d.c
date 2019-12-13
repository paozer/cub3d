/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 21:55:21 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map	*map;
//	void	*mlx_ptr;
//	void	*mlx_win;
	(void)argc;

	/* add argc check with appropriate error message */
	map = ft_parsing(argv[1]);
//	ft_print_parsing(map);
//	ft_print_map(map->map);
	ft_raycasting(map);
/*
	if ((mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((mlx_win = mlx_new_window(mlx_ptr, map->res_ptr->x, map->res_ptr->y, "cube3d")) == NULL)
		return (0);
	mlx_loop(mlx_ptr);
*/
	return (0);
}
