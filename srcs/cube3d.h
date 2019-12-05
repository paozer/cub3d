/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cube3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:12:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 01:31:44 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include <fcntl.h>

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
}				t_textures;

typedef struct	s_map
{
	char		*map;
	t_textures	*text_ptr;
	t_colour	*floor_ptr;
	t_colour	*ceiling_ptr;
}				t_map;

int		ft_check_map(void);
int		ft_parsing(void);

#endif
