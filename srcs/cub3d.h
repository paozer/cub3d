/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:12:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 01:46:30 by pramella    ###    #+. /#+    ###.fr     */
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
# define IMG map->img
# define TEXT map->texture
# define TEXT_P map->texture_path
# define RES map->resolution
# define FLO_CLR map->flo_clr
# define CEI_CLR map->cei_clr
# define SPEED .1
# define ROTSPEED .05
# define ALL FLO_CLR && CEI_CLR && MLX && RES && SCREEN && PLAYER && RAY && SPR

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
	double		*wall_dist;
	t_spr		**arr;
	double		inv_deter;
	double		x;
	double		y;
	double		trans_x;
	double		trans_y;
	int			screen_x;
	int 		height;
	int 		width;
	int 		draw_start_y;
	int 		draw_end_y;
	int 		draw_start_x;
	int 		draw_end_x;
	int 		tex_x;
	int 		tex_y;
}				t_sprite;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
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
	int			width;
	int			height;
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
void			check_color(int r, int g, int b, t_map *map);
void			set_map(t_map *map, int fd, char *line);
void			set_player(t_map *map, int x, int y);
void			init(t_map *map);
t_map			*init_map(void);

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
void			init_sprites(t_map *map);

/*
 ** UTILITYS
*/
void			print_error(int flag, void *arg, t_map *map, int free_flag);
void			free_all(t_map *map, int flag);
int				free_dummy(t_map *map);
char			*ft_strdup_mod(char *str);


/*
 ** helper functions for debugging
*/
void			ft_print_parsing(t_map *map);
void			ft_print_map(char **map);
void			ft_print_map_i(int **map, int wd, int ht);
void			ft_print_spr(t_map *map);

#endif
