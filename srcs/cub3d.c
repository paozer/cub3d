/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 07:10:30 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

int		main(int argc, char **argv)
{
	t_map	*m;

	if (argc < 2 || argc > 3)
	{
		ft_printf("Error\nUsage: ./cube3d path/to/map.cub\n");
		ft_printf("-save: saves first image to bmp file and quits\n");
		return (0);
	}
	m = parsing(argv[1]);
	if (argc == 3)
	{
		ft_strncmp(argv[2], "-save", 6) ? print_error(11, (void *)0, m, 1) : 0;
		m->save = (ft_strncmp(argv[2], "-save", 6) == 0 &&
			ft_strlen(argv[2]) == 5) ? 1 : 0;
	}
	init(m);
	init_sprites(m);
	start(m);
	return (0);
}
