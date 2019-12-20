/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   raycasting_sprites.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <pramella@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/19 21:45:59 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/20 00:45:23 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../cub3d.h"

void	lst_sort(t_map *map)
{
	t_lst *prev;
	t_lst *curr;

	curr = SPR_LST;
	prev = SPR_LST;
	while (curr && curr->next)
	{
		if (curr->dist > curr->next->dist)
		{
			prev->next = curr->next;
			if (curr->next->next)
			{
				curr->next = curr->next->next;
				curr->next->next = curr;
			}
			else
			{
				curr->next->next = curr;
				curr->next = NULL;
			}
			curr = SPR_LST;
			prev = SPR_LST;
		}
		else
		{
			prev = curr;
			curr = curr->next;
		}
	}

}

void	sprites_main(t_map *map)
{
	t_lst *node;

	node = SPR->lst;
	while (node)
	{
		node->dist = sqrt(pow(PLAYER->x - node->x, 2)
			+ pow(PLAYER->y - node->y, 2));
		node = node->next;
	}
	lst_sort(map);
}
