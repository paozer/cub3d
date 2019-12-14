/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_draw.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/14 17:50:21 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/14 18:25:15 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

void		draw(t_map *map)
{
	int		y;
	int		draw_start;
	int		draw_end;
	void	*img_ptr;

	y = 0;
	draw_start = (map->res_ptr->y - RAY->line_h) / 2;
	draw_end = map->res_ptr->y - RAY->line_h;
	while (y < map->res_ptr->y)
	{
		if (y >= 0 && y < draw_start)
		{
			// print ceiling
		}
		else if (y >= draw_start && y < draw_end)
		{
			// print wall
		}
		else
		{
			// print floor
		}
	}
}
