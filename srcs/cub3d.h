/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:12:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 19:09:43 by pramella    ###    #+. /#+    ###.fr     */
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
# define MOVT map->movt
# define RAY map->ray
# define MLX map->mlx
# define SPR map->sprites
# define SPR_LST map->sprites->lst
# define IMG map->img
# define FLOOR map->floor_ptr
# define TEXT map->texture
# define TEXT_P map->texture_path
# define RES map->resolution
# define SPEED .1
# define ROTSPEED .05

typedef struct	s_res
{
	int			x;
	int			y;
}				t_res;

typedef struct	s_spr
{
	double		dist;
	double		x;
	double		y;
}				t_spr;

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
	double		plane_x;
	double		plane_y;
	double		cam_x;
	double		cam_y;
}				t_screen;

typedef struct	s_ray
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	int			step_x;
	int			step_y;
	int			side;
	int			hit;
	double		wall_dist;
	int			line_h;
}				t_ray;

typedef struct	s_img
{
	void		*img;
	int			*buf;
	int			bpp;
	int			size_line;
	int			height;
	int			width;
	int			endian;
}				t_img;

typedef struct 	s_sprite
{
	int			nbr;
	double		**wall_dist;
	t_spr		**arr;
}				t_sprite;

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
	t_res		*resolution;

	t_player	*player;
	t_movt		*movt;
	t_screen	*screen;
	t_ray		*ray;

	char		*texture_path[5];
	t_img		*texture[5];
	t_sprite	*sprites;
	int			*flo_clr;
	int			*cei_clr;

	t_mlx		*mlx;
	t_img		*img;
}				t_map;

/*
 ** PARSING
*/
t_map			*parsing(char *params);
void			check_parsing(t_map *map);
void			check_color(int r, int g, int b);
void			set_map(t_map *map, int fd, char **line);
void			set_player(t_map *map, int x, int y);
t_map			*init_map(void);
void			print_error(int flag, void *arg);

/*
 ** RAYCASTING
*/
void			start(t_map *map);
void			raycasting(t_map *map);
void			draw(t_map *map, int x);
int				movt_do(t_map *map);
int				movt_pressed(int key_code, t_map *map);
int				movt_released(int key_code, t_map *map);
void			movt_front_back(int key_code, t_map *map);
void			movt_left_right(int key_code, t_map *map);
int				rot_left_right(int key_code, t_map *map);
void			sprites_main(t_map *map);

//t_lst			*lstnew(int x, int y);
//void			lstadd_front(t_lst **alst, t_lst *new);
/*
 ** helper functions for debugging
*/
void			ft_print_parsing(t_map *map);
void			ft_print_map(char **map);
void			ft_print_map_i(int **map, int wd, int ht);
void			ft_print_spr(t_map *map);

#endif
