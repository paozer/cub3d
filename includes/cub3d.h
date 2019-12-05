/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:12:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 16:24:55 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stddef.h>

typedef struct	s_colour
{
	int			red;
	int			green;
	int			blue;
}				t_colour;

typedef struct	s_textures
{
	char		*north;
	char		*south;
	char		*west;
	char		*east;
	char		*sprite;
}				t_textures;

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_map
{
	char		*map;
	t_res		*res_ptr;
	t_textures	*text_ptr;
	t_colour	*floor_ptr;
	t_colour	*ceiling_ptr;
}				t_map;

int		ft_parsing(char *params, t_map *map);

#endif
