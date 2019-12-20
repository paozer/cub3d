/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   trash_utils.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/11 23:01:54 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 00:08:25 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_player(t_map *map)
{
	printf("-------PLAYER-------\n");
	printf("player->pos_x = \t %f\n", map->player->x);
	printf("player->pos_y = \t %f\n", map->player->y);
	printf("player->dir_x = \t %f\n", map->player->dir_x);
	printf("player->dir_y = \t %f\n", map->player->dir_y);
	ft_printf("player->flag = \t\t %d\n", map->player->set_flag);
	ft_printf("map->dircase = \t\t %c\n",
				map->map[(int)PLAYER->y][(int)PLAYER->x]);
}

void	ft_print_sprite_list(t_map *map)
{
	int i = 1;
	t_lst *node;
	node = SPR_LST;
	ft_printf("--------------SPRITES--------------\n");
	while (node)
	{
		printf("NODE [%2d]\n", i++);
		printf("SPR_LST->dist = [%f]\n", node->dist);
		printf("SPR_LST->x = [%f]\n", node->x);
		printf("SPR_LST->y = [%f]\n", node->y);
		ft_printf("-----------------------------------\n");
		node = node->next;
	}
}
/*
void	ft_print_screen(t_map *map)
{
	printf("-------SCREEN-------\n");
	printf("SCREEN->plane_x = [%f]\n", SCREEN->plane_x);
	printf("SCREEN->plane_y = [%f]\n", SCREEN->plane_y);
	printf("SCREEN->cam_x = [%f]\n", SCREEN->cam_x);
	printf("SCREEN->cam_y = [%f]\n", SCREEN->cam_y);
}

void	ft_print_parsing(t_map *map)
{
	ft_printf("map->res_ptr->x = \t%d\n", map->res_ptr->x);
	ft_printf("map->res_ptr->y = \t%d\n", map->res_ptr->y);
	ft_printf("TEXT_P[north] = \t%s\n", TEXT_P[0]);
	ft_printf("TEXT_P[south] = \t%s\n", TEXT_P[1]);
	ft_printf("TEXT_P[west] = \t%s\n", TEXT_P[2]);
	ft_printf("TEXT_P[east] = \t%s\n", TEXT_P[3]);
	ft_printf("TEXT_P[sprite] = \t%s\n", TEXT_P[4]);
	ft_printf("map->floor_ptr = \t RGB (%d, %d, %d)\n",
					map->floor_ptr->red, map->floor_ptr->green,
					map->floor_ptr->blue);
	ft_printf("map->ceiling_ptr = \t RGB (%d, %d, %d)\n",
					map->ceiling_ptr->red, map->ceiling_ptr->green,
					map->ceiling_ptr->blue);
	ft_printf("map->map_width = \t %d\n", map->map_width);
	ft_printf("map->map_height = \t %d\n", map->map_height);
	ft_print_player(map);
	ft_print_screen(map);
	printf("-------RAY-------\n");
	printf("RAY->x = [%f]\n", RAY->x);
	printf("RAY->y = [%f]\n", RAY->y);
	printf("RAY->dir_x = [%f]\n", RAY->dir_x);
	printf("RAY->dir_y = [%f]\n", RAY->dir_y);
	printf("RAY->map_x = [%d]\n", RAY->map_x);
	printf("RAY->map_y = [%d]\n", RAY->map_y);
	printf("RAY->side_dist_x = [%f]\n", RAY->side_dist_x);
	printf("RAY->side_dist_y = [%f]\n", RAY->side_dist_y);
	printf("RAY->delta_dist_x = [%f]\n", RAY->delta_dist_x);
	printf("RAY->delta_dist_y = [%f]\n", RAY->delta_dist_y);
	printf("RAY->step_x = [%d]\n", RAY->step_x);
	printf("RAY->step_y = [%d]\n", RAY->step_y);
	printf("RAY->side = [%d]\n", RAY->side);
	printf("RAY->hit = [%d]\n", RAY->hit);
	printf("RAY->wall_dist = [%f]\n", RAY->wall_dist);
}

void	ft_print_map(char **map)
{
	int i;

	i = 0;
	ft_printf("\n");
	while (map[i])
	{
		printf("map[%2d] [%s]\n", i, map[i]);
		++i;
	}
}

void	ft_print_map_i(int **map, int wd, int ht)
{
	int i;
	int j;

	i = 0;
	ft_printf("\n");
	while (i < ht)
	{
		ft_printf("map[%2d] {", i);
		j = 0;
		while (j < wd)
		{
			ft_printf("%d", map[i][j]);
			++j;
		}
		ft_printf("}\n");
		++i;
	}
}
*/
