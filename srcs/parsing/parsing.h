/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/05 20:30:56 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/11 23:42:28 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "../cub3d.h"

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

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

typedef struct	s_player
{
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	int			set_flag;
}				t_player;

typedef struct	s_calcs
{
	double		plane_x;
	double		plane_y;
	double		time;
	double		prev_time;
}				t_calcs;

typedef struct	s_map
{
	char		**map;
	int			**map_i;
	int			map_width;
	int			map_height;
	t_player	*player;
	t_calcs		*vectors;
	t_res		*res_ptr;
	t_textures	*text_ptr;
	t_color		*floor_ptr;
	t_color		*ceiling_ptr;
}				t_map;

int				ft_parsing(char *params, t_map **map);
t_map			*ft_init_map(void);
void			ft_parsing_check(t_map **map);
void			ft_print_error(int flag, void *arg);
void			ft_set_map(t_map **map, int fd, char **line);
void			ft_init_player(t_map **map, int x, int y);

#endif
