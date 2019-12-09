/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_check.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/06 16:22:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 20:20:55 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

void		ft_print_error(int flag, void *arg)
{
	write(1, "Error\n", 6);
	(flag == 0) ? ft_printf("Resolution is not valid.\n") : 1;
	(flag == 1) ? ft_printf("Color [%d] is not an RGB value.\n",
				*((int *)arg)) : 1;
	(flag == 2) ? ft_printf("File \"%s\" does not exist.\n", arg) : 1;
	(flag == 3) ? ft_printf("Path extension \"%s\" is not valid.\n", arg) : 1;
	exit(0);
}

static void	ft_color_check(t_color *color_ptr)
{
	(color_ptr->red < 0 || color_ptr->red > 255) ?
		ft_print_error(1, &(color_ptr->red)) : 0;
	(color_ptr->green < 0 || color_ptr->green > 255) ?
		ft_print_error(1, &(color_ptr->red)) : 0;
	(color_ptr->blue < 0 || color_ptr->blue > 255) ?
		ft_print_error(1, &(color_ptr->red)) : 0;
}

static void	ft_path_check(char *path)
{
	int		fd;
	size_t	len;

	if ((fd = open(path, O_RDONLY)) == -1)
		ft_print_error(2, path);
	close(fd);
	len = ft_strlen(path) - 4;
	if (ft_strncmp(path + len, ".xpm", 4) != 0)
		ft_print_error(3, path);
}

void		ft_parsing_check(t_map **map)
{
	((*map)->res_ptr->x <= 0 || (*map)->res_ptr->y <= 0) ?
		(ft_print_error(0, (void *)0)) : 1;
	ft_path_check((*map)->text_ptr->north);
	ft_path_check((*map)->text_ptr->south);
	ft_path_check((*map)->text_ptr->west);
	ft_path_check((*map)->text_ptr->east);
	ft_path_check((*map)->text_ptr->sprite);
	ft_color_check((*map)->floor_ptr);
	ft_color_check((*map)->ceiling_ptr);
}
