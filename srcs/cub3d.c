/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 18:10:08 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_print_parsing(t_map *map)
{
	ft_printf("map->res_ptr->x = \t%d\n", map->res_ptr->x);
	ft_printf("map->res_ptr->y = \t%d\n", map->res_ptr->y);
	ft_printf("map->text_ptr->north = \t%s\n", map->text_ptr->north);
	ft_printf("map->text_ptr->south = \t%s\n", map->text_ptr->south);
	ft_printf("map->text_ptr->west = \t%s\n", map->text_ptr->west);
	ft_printf("map->text_ptr->east = \t%s\n", map->text_ptr->east);
	ft_printf("map->text_ptr->sprite = %s\n", map->text_ptr->sprite);
	ft_printf("map->floor_ptr = \t RGB (%d, %d, %d)\n",
					map->floor_ptr->red, map->floor_ptr->green,
					map->floor_ptr->blue);
	ft_printf("map->ceiling_ptr = \t RGB (%d, %d, %d)\n",
					map->ceiling_ptr->red, map->ceiling_ptr->green,
					map->ceiling_ptr->blue);
	ft_printf("map->map_width = \t %d\n", map->map_width);
	ft_printf("map->map_height = \t %d\n", map->map_height);
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

int		main(int argc, char **argv)
{
	t_map *map;
	(void)argc;

	ft_parsing(argv[1], &map);
	ft_print_parsing(map);
	ft_print_map(map->map);
	ft_print_map_i(map->map_i, map->map_width, map->map_height);
	return (0);
}
