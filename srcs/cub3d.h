/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:12:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/12 15:26:52 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include "../X11/includes/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# include <stdio.h>

# define PLAYER map->player

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
	int			set_flag;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
}				t_player;


typedef struct	s_screen
{
	double		plane_x;
	double		plane_y;
	double		cam_x;
	double		cam_y;
}				t_screen;

typedef struct	s_ray
{
	double		ray_x;
	double		ray_y;
	double		ray_dir_x;
	double		ray_dir_y;
	double		map_x;
	double		map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		side_x;
	double		side_y;
}				t_ray;

typedef struct	s_map
{
	char		**map;
	int			**map_i;
	int			map_width;
	int			map_height;

	t_player	*player;
	t_screen	*screen;
	t_ray		*ray;

	t_res		*res_ptr;
	t_textures	*text_ptr;
	t_color		*floor_ptr;
	t_color		*ceiling_ptr;
/* pour mlx stuff	t_mlx		*mlx; */
}				t_map;


/* PARSING */
int				ft_parsing(char *params, t_map **map);

void			ft_parsing_check(t_map **map);
void			ft_print_error(int flag, void *arg);

void			ft_set_map(t_map **map, int fd, char **line);

void			ft_init_player(t_map **map, int x, int y);
t_map			*ft_init_map(void);

/* RAYCASTING */
void			ft_raycasting(t_map *map);

/* helper functions for debugging */

void			ft_print_parsing(t_map *map);
void			ft_print_map(char **map);
void			ft_print_map_i(int **map, int wd, int ht);

#endif
