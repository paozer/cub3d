/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstnew.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/13 12:51:44 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 10:43:57 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *lst;

	if (!(lst = malloc(sizeof(*lst))))
		return (NULL);
	lst->content = content;
	lst->next = NULL;
	return (lst);
}
