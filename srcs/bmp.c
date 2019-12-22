/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bmp.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 06:20:46 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 10:28:10 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"

void	pixels_to_bitmap(t_map *map, int fd, t_bmp_header bih)
{
	int				x;
	int				y;
	int				rgb;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = 0;
	while (y < RES->y)
	{
		x = 0;
		while (x < RES->x)
		{
			rgb = map->img->buf[x + y * RES->x];
			color[0] = rgb % 256;
			rgb /= 256;
			color[1] = rgb % 256;
			rgb /= 256;
			color[2] = rgb % 256;
			write(fd, &color, sizeof(color));
			++x;
		}
		++y;
	}
}

void	create_header_file(const char *filename, t_map *map)
{
	int				fd;
	t_file_header	bfh;
	t_bmp_header	bih;

	ft_memcpy(&bfh.bitmap_type, "BM", 2);
	bfh.file_size = RES->x * RES->y * 4 + 54;
	bfh.reserved1 = 0;
	bfh.reserved2 = 0;
	bfh.offset_bits = 0;
	bih.size_header = sizeof(bih);
	bih.width = RES->x;
	bih.height = RES->y;
	bih.planes = 1;
	bih.bit_count = 24;
	bih.compression = 0;
	bih.image_size = RES->x * RES->y * 4 + 54;
	bih.ppm_x = 2;
	bih.ppm_y = 2;
	bih.clr_used = 0;
	bih.clr_important = 0;
	fd = open(filename, O_CREAT | O_RDWR, 0666);
	write(fd, &bfh, 14);
	pixels_to_bitmap(map, fd, bih);
	close(fd);
}

void	map_to_bmp(t_map *map)
{
	create_header_file("cub3D.bmp", map);
	free_all(map, 3);
}
