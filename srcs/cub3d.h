/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cub3d.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 14:12:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/11 02:46:57 by pramella    ###    #+. /#+    ###.fr     */
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

# define SPEED .1
# define ROTSPEED .05

typedef struct		s_res
{
	int				x;
	int				y;
}					t_res;

typedef struct		s_spr
{
	double			dist;
	double			x;
	double			y;
}					t_spr;

typedef struct		s_player
{
	int				set_flag;
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
}					t_player;

typedef struct		s_screen
{
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			cam_y;
}					t_screen;

typedef struct		s_ray
{
	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	int				step_x;
	int				step_y;
	int				side;
	int				hit;
	double			wall_dist;
	int				line_h;
}					t_ray;

typedef struct		s_img
{
	void			*img;
	int				*buf;
	int				bpp;
	int				size_line;
	int				height;
	int				width;
	int				endian;
	int				tex_x;
	int				tex_y;
	double			wall_x;
	int				draw_start;
	int				draw_end;
}					t_img;

typedef struct		s_sprite
{
	int				nbr;
	double			*wall_dist;
	t_spr			**arr;
	double			inv_deter;
	double			x;
	double			y;
	double			trans_x;
	double			trans_y;
	int				screen_x;
	int				height;
	int				width;
	int				draw_start_y;
	int				draw_end_y;
	int				draw_start_x;
	int				draw_end_x;
	int				tex_x;
	int				tex_y;
}					t_sprite;

typedef struct		s_file_header
{
	unsigned char	bitmap_type[2];
	int				file_size;
	short			reserved1;
	short			reserved2;
	unsigned int	offset_bits;
}					t_file_header;

typedef struct		s_bmp_header
{
	unsigned int	size_header;
	unsigned int	width;
	unsigned int	height;
	short int		planes;
	short int		bit_count;
	unsigned int	compression;
	unsigned int	image_size;
	unsigned int	ppm_x;
	unsigned int	ppm_y;
	unsigned int	clr_used;
	unsigned int	clr_important;
}					t_bmp_header;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_mlx;

typedef struct		s_movt
{
	int				front;
	int				back;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
}					t_movt;

typedef struct		s_map
{
	char			**map;
	int				**map_i;
	int				width;
	int				height;
	int				config_flag;

	t_res			*re;
	t_player		*p;
	t_movt			*mo;
	t_screen		*s;
	t_ray			*ra;
	char			*tp[5];
	t_img			*t[5];
	t_sprite		*sp;
	int				*fc;
	int				*cc;
	int				flag_clr;
	t_mlx			*mx;
	t_img			*i;
	int				save;
}					t_map;

t_map				*parsing(char *params);
void				check_parsing(t_map *m);
void				check_color(int *c, t_map *m);
void				set_map(t_map *m, int fd, char *line);
void				set_player(t_map *m, int x, int y);
void				init(t_map *m);
t_map				*init_map(void);

void				start(t_map *m);
void				raycasting(t_map *m);
void				draw(t_map *m, int x);
int					movt_do(t_map *m);
int					movt_pressed(int key_code, t_map *m);
int					movt_released(int key_code, t_map *m);
void				movt_front_back(int key_code, t_map *m);
void				movt_left_right(int key_code, t_map *m);
int					rot_left_right(int key_code, t_map *m);
void				sprites_main(t_map *m);
void				init_sprites(t_map *m);

void				print_error(int flag, void *arg, t_map *m, int free_flag);
void				free_all(t_map *m, int flag);
int					free_dummy(t_map *m);
char				*ft_strdup_mod(char *str);
char				*set_paths(char *line, t_map *m, int t);
void				map_to_bmp(t_map *m);
void				ft_atoi_pos_return(char *s, int *c, int *i);

#endif
