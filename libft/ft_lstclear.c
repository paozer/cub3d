/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstclear.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 12:50:29 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 14:52:37 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *current;
	t_list *trash;

	if (lst == NULL || *lst == NULL || (*del) == NULL)
		return ;
	current = *lst;
	while (current)
	{
		trash = current->next;
		ft_lstdelone(current, (*del));
		current = trash;
	}
	*lst = NULL;
}
