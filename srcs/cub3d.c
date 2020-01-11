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
	t_map	*m;

	if (argc < 2)
	{
		ft_printf("Error\nUsage: ./cube3d path/to/map.cub\n");
		return (0);
	}
	m = parsing(argv[1]);
	if (argc == 3)
		m->save = (ft_strncmp(argv[2], "-save", 6) == 0) ? 1 : 0;
	init(m);
	init_sprites(m);
	start(m);
	return (0);
}
