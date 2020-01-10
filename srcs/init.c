/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 18:32:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/24 14:38:24 by paozer      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

t_map	*init_map(void)
{
	t_map	*map;

	if (!(map = malloc(sizeof(*map))))
		print_error(8, NULL, NULL, 0);
	map->fc = malloc(sizeof(*map->fc));
	map->cc = malloc(sizeof(*map->cc));
	map->flag_clr = 0;
	map->mx = malloc(sizeof(*map->mx));
	map->re = malloc(sizeof(*map->re));
	map->s = malloc(sizeof(*map->s));
	map->p = malloc(sizeof(*map->p));
	(map->p) ? map->p->set_flag = 0 : 0;
	map->ra = malloc(sizeof(*map->ra));
	map->sp = malloc(sizeof(*map->sp));
	map->sp->nbr = 0;
	map->save = 0;
	map->config_flag = 0;
	if (!(map && map->fc && map->cc && map->mx && map->re && map->s && map->p && map->ra && map->sp))
		print_error(8, NULL, map, 1);
	return (map);
}

void	init_sprites(t_map *map)
{
	int i;
	int j;
	int y;

	if (!(map->sp->arr = malloc(sizeof(*map->sp->arr) * (map->sp->nbr + 1))))
		return ;
	map->sp->arr[map->sp->nbr] = NULL;
	i = -1;
	y = 0;
	while (++i < map->height)
	{
		j = -1;
		while (++j < map->width)
		{
			if (map->map_i[i][j] == 2)
			{
				if (!(map->sp->arr[y] = malloc(sizeof(*map->sp->arr[y]))))
					return ;
				map->sp->arr[y]->x = i + .5;
				map->sp->arr[y++]->y = j + .5;
			}
		}
	}
	if (!(map->sp->wall_dist = malloc(sizeof(*map->sp->wall_dist) * map->re->x)))
		return ;
}

void	init(t_map *map)
{
	int i;

	i = 0;
	if ((map->mx->mlx_ptr = mlx_init()) == NULL)
		return ;
	if ((map->mx->win_ptr = mlx_new_window(map->mx->mlx_ptr, map->re->x, map->re->y,
					"cube3d")) == NULL)
		return ;
	if (!(map->i = malloc(sizeof(*(map->i)))))
		return ;
	map->i->img = mlx_new_image(map->mx->mlx_ptr, map->re->x, map->re->y);
	map->i->buf = (int *)mlx_get_data_addr(map->i->img, &map->i->bpp,
			&map->i->size_line, &map->i->endian);
	while (i < 5)
	{
		if (!(map->t[i] = malloc(sizeof(t_img))))
			return ;
		map->t[i]->img = mlx_xpm_file_to_image(map->mx->mlx_ptr, map->tp[i],
				&map->t[i]->width, &map->t[i]->height);
		map->t[i]->buf = (int *)mlx_get_data_addr(map->t[i]->img, &map->t[i]->bpp,
				&map->t[i]->size_line, &map->t[i]->endian);
		++i;
	}
}
