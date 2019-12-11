/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_init.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 18:32:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 22:28:20 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

static t_res		*ft_init_res(void)
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

static t_color		*ft_init_color(void)
{
	t_color *ptr;

	if (!(ptr = malloc(sizeof(*ptr))))
		return (NULL);
	ptr->red = -1;
	ptr->green = -1;
	ptr->blue = -1;
	return (ptr);
}

void				ft_init_player(t_map **map, int x, int y)
{
	if ((*map)->player->set_flag == 1)
		ft_print_error(6, (void *)0);
	(*map)->player->set_flag = 1;
	(*map)->player->pos_x = x + .5;
	(*map)->player->pos_y = y + .5;
	if ((*map)->map[y][x] == 'N' || (*map)->map[y][x] == 'S')
		(*map)->player->dir_x = 0;
	if ((*map)->map[y][x] == 'N')
		(*map)->player->dir_y = 1;
	if ((*map)->map[y][x] == 'S')
		(*map)->player->dir_y = -1;
	if ((*map)->map[y][x] == 'E' || (*map)->map[y][x] == 'W')
		(*map)->player->dir_y = 0;
	if ((*map)->map[y][x] == 'E')
		(*map)->player->dir_x = -1;
	if ((*map)->map[y][x] == 'W')
		(*map)->player->dir_x = 1;
}

t_map				*ft_init_map(void)
{
	t_map *map;

	if (!(map = malloc(sizeof(*map))))
		return (NULL);
	map->map = NULL;
	if (!(map->player = malloc(sizeof(*(map->player)))))
		return (NULL);
	map->player->set_flag = 0;
	map->res_ptr = ft_init_res();
	map->text_ptr = ft_init_textures();
	map->floor_ptr = ft_init_color();
	map->ceiling_ptr = ft_init_color();
	return (map);
}
