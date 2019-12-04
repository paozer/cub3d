/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/11 17:55:34 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 15:22:38 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *node;
	t_list *last;

	if (lst == NULL || (*f) == NULL)
		return (NULL);
	if (!(head = ft_lstnew((*f)(lst->content))))
		return (NULL);
	lst = lst->next;
	last = head;
	while (lst)
	{
		if (!(node = ft_lstnew((*f)(lst->content))))
		{
			ft_lstclear(&head, (*del));
			return (NULL);
		}
		last->next = node;
		last = node;
		lst = lst->next;
	}
	return (head);
}
