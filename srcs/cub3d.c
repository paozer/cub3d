/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 07:02:28 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
	{
		ft_printf("Error\nUsage: ./cube3d path/to/map.cub\n");
		return (0);
	}
	map = parsing(argv[1]);
	if (argc == 3)
		map->save = (ft_strncmp(argv[2], "-save", 6) == 0) ? 1 : 0;
	init(map);
	init_sprites(map);
	start(map);
	return (0);
}
