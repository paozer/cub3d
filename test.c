/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:21:57 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 14:38:32 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "X11/includes/mlx.h"
#include <stdlib.h>

int		main(void)
{
	void *mlx_ptr;
	void *mlx_win;

	if ((mlx_ptr = mlx_init()) == NULL)
		return (0);
	if ((mlx_win = mlx_new_window(mlx_ptr, 900, 500, "cube3d")) == NULL)
		return (0);
	mlx_loop(mlx_ptr);
	return (0);
}