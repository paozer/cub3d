/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:11:33 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 14:18:52 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		main(int argc, char **argv)
{
	t_map *map;

	if (!(map = malloc(sizeof(*map))))
		return (-1);
	if (!(map->text_ptr = malloc(sizeof(*map->text_ptr))))
		return (-1);
	if (!(map->floor_ptr = malloc(sizeof(*map->floor_ptr))))
		return (-1);
	if (!(map->ceiling_ptr = malloc(sizeof(*map->ceiling_ptr))))
		return (-1);
	ft_parsing(argv[1], map);
	return (0);
}
