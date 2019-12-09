/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   parsing_map.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/09 20:57:17 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 22:36:53 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "parsing.h"

void	ft_realloc()
{

}

void	ft_set_map(int fd, char **line)
{
	int		i;
	char	**map;

	i = 1;
	if (!(map = malloc(sizeof(map) * 2)))
		return ;
	map[0] = *line;
	while (get_next_line(fd, &map[i]) == 1)
	{

	}
}
