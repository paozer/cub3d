/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 18:32:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 16:24:42 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

static t_res	*ft_init_res(void)
{
	t_res *ptr;

	if (!(ptr = malloc(sizeof(*ptr))))
		return (NULL);
	ptr->x = -1;
	ptr->y = -1;
	return (ptr);
}

static t_textures	*ft_init_textures(void)
{
	t_textures *ptr;

	if (!(ptr = malloc(sizeof(*ptr))))
		return (NULL);
	ptr->north = NULL;
	ptr->south = NULL;
	ptr->west = NULL;
	ptr->east = NULL;
	ptr->sprite = NULL;
	return (ptr);
}

static t_color *ft_init_color(void)
{
	t_color *ptr;

	if (!(ptr = malloc(sizeof(*ptr))))
		return (NULL);
	ptr->red = -1;
	ptr->green = -1;
	ptr->blue = -1;
	return (ptr);
}

t_map	*ft_init_map(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(*map))))
		return (NULL);
	map->map = NULL;
	map->res_ptr = ft_init_res();
	map->text_ptr = ft_init_textures();
	map->floor_ptr = ft_init_color();
	map->ceiling_ptr = ft_init_color();
	return (map);
}
