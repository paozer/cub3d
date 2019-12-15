/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:12:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/15 19:44:41 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include "../X11/includes/mlx.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"

# include <stdio.h>

# define PLAYER map->player
# define SCREEN map->screen
# define RAY map->ray
# define MLX map->mlx
# define IMG map->img
# define FLOOR map->floor
# define CEILING map->ceiling
# define TEXT map->text_ptr
# define RES map->res_ptr
# define MOVT map->movt
# define SPEED .1
# define ROTSPEED .02

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
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
}				t_player;


typedef struct	s_screen
{
	double		plane_x; // coordinates of plane perp to dir of player
	double		plane_y;
	double		cam_x; // position of ray on the plane/screen
	double		cam_y;
}				t_screen;

typedef struct	s_ray
{
	double		x; // exact position of ray
	double		y;
	double		dir_x; // direction of the ray
	double		dir_y;
	int			map_x; // box of the map where ray is
	int			map_y;
	double		side_dist_x; // initial distance until x hit
	double		side_dist_y;
	double		delta_dist_x; // distance between hits
	double		delta_dist_y;
	int			step_x; // what direction to step in
	int			step_y;
	int			side; // what kind of wall NS/EW was hit
	int			hit; // did we hit a wall
	double		wall_dist;
	int			line_h;
}				t_ray;

typedef struct	s_img
{
	void		*img;
	int			*buf;
	int			bpp;
	int			size_line;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*data_addr;
}				t_mlx;

typedef struct	s_movt
{
	int			front;
	int			back;
	int			right;
	int			left;
	int			rot_right;
	int			rot_left;
}				t_movt;

typedef struct	s_map
{
	char		**map;
	int			**map_i;
	int			map_width;
	int			map_height;

	t_movt		*movt;

	t_player	*player;
	t_screen	*screen;
	t_ray		*ray;

	t_res		*res_ptr;
	t_textures	*text_ptr;
	t_color		*floor_ptr;
	t_color		*ceiling_ptr;

	t_mlx		*mlx;
	t_img		*img;
}				t_map;

/* PARSING */
t_map			*ft_parsing(char *params);
void			ft_parsing_check(t_map *map);
void			ft_set_map(t_map *map, int fd, char **line);
void			ft_set_player(t_map *map, int x, int y);
t_map			*ft_init_map(void);

/* RAYCASTING */
void			start(t_map *map);
void			ft_raycasting(t_map *map);
void			draw(t_map *map, int x);
int	movt_do(t_map *map);
int	movt_pressed(int key_code, t_map *map);
int	movt_released(int key_code, t_map *map);

/* UTILITYS */
double			ft_abs(double value);
void			ft_print_error(int flag, void *arg);

/* helper functions for debugging */

void			ft_print_parsing(t_map *map);
void			ft_print_map(char **map);
void			ft_print_map_i(int **map, int wd, int ht);

#endif
