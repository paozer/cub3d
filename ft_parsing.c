/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_parsing.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/04 19:29:14 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 02:03:04 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

int		ft_parsing(char *params)
{
	int		fd;
	int		ret;
	char	*line;

	if ((fd = open(params, O_RDONLY)) == -1)
		return (-1);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		while ((line[i] > 8 && line[i] < 14) || line[i] == 32)
				++i;
		(line [i] == 'R') ? ft_resolution(line) : 1;
		(line [i] == 'N' && line[i + 1] == 'O') ? ft_resolution(line) : 1;
		(line [i] == 'N' && line[i + 1] == 'O') ? ft_resolution(line) : 1;
	}
}
