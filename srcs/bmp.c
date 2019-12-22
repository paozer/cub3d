/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   bmp.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/22 06:20:46 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/22 09:10:30 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cub3d.h"
void	bitmap_image(t_map *map, int fd, t_header2 bih)
{
	int				x;
	int				y;
	int				ble;
	unsigned char	color[3];

	write(fd, &bih, sizeof(bih));
	y = RES->y - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < RES->x)
		{
			ble = IMG->buf[x + y * RES->x];
			color[0] = ble % 256;
			ble /= 256;
			color[1] = ble % 256;
			ble /= 256;
			color[2] = ble % 256;
			write(fd, &color, sizeof(color));
			x++;
		}
		y--;
	}
}

void	save_bitmap(const char *filename, t_map *map)
{
	int			fd;
	t_header	bfh;
	t_header2	bih;

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
	close(open(filename, O_WRONLY | O_CREAT));
	fd = open(filename, O_RDWR);
	write(fd, &bfh, 14);
	bitmap_image(map, fd, bih);
	close(fd);
}

void    map_to_bmp(t_map *map)
{
	save_bitmap("cub3D.bmp", map);
	free_all(map, 3);
}
