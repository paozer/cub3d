/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   utils.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 22:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 00:08:15 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(int flag, void *arg, t_map *map, int free_flag)
{
	write(1, "Error\n", 6);
	(flag == 0) ? ft_printf("Resolution is not valid.\n") : 1;
	(flag == 1) ? ft_printf("Color [%d] is not an RGB value.\n",
			*((int *)arg)) : 1;
	(flag == 2) ? ft_printf("File \"%s\" does not exist.\n", arg) : 1;
	(flag == 3) ? ft_printf("Path extension \"%s\" is not valid.\n", arg) : 1;
	(flag == 4) ? ft_printf("Map character \"%c\" is not valid.\n",
			*((char *)arg)) : 1;
	(flag == 5) ? ft_printf("Map is not enclosed by walls in row %d.\n",
			*((int *)arg) + 1) : 1;
	(flag == 6) ? ft_printf("Multiple or no start positions for player.\n") : 1;
	(flag == 7) ? ft_printf("No start position for player.\n") : 1;
	(flag == 8) ? ft_printf("Could not allocate sufficient memory.\n") : 1;
	free_all(map, free_flag);
}

int		free_dummy(t_map *map)
{
	free_all(map, 2);
	return (0);
}

void	free_all(t_map *map, int flag)
{
	int i;
	int w = RES->x;

	i = 0;
	if (flag != 0)
	{
		free(CEI_CLR);
		free(FLO_CLR);
		(flag == 1) ? free(SPR) : 0;
		(flag == 1) ? free(MLX) : 0;
		free(SCREEN);
		free(RAY);
		free(PLAYER);
		free(RES);
		while (i < 5)
			free(TEXT_P[i++]);
		i = 0;
		while (map->map[i])
			free(map->map[i++]);
		free(map->map[i]);
		free(map->map);
		i = 0;
		while (i < map->height)
			free(map->map_i[i++]);
		free(map->map_i);
	}
	if (flag == 2)
	{
		mlx_destroy_window (MLX->mlx_ptr, MLX->win_ptr);
		free(MLX);
		free(MOVT);
		i = 0;
		while (i < 5)
		{
			free(TEXT[i]->img);
			free(TEXT[i]->buf);
			free(TEXT[i++]);
		}
		i = 0;
		while (i < w)
			free (SPR->wall_dist[i++]);
		free(SPR->wall_dist);
		i = 0;
		while (SPR->arr[i])
			free(SPR->arr[i++]);
		free(SPR->arr);
		free(SPR);
		free(IMG->img);
		free(IMG->buf);
		free(IMG);
	}
	free(map);
	while (1) ;
	exit(0);
}
