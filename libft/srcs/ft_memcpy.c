/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 11:49:54 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/18 11:00:06 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*p_dst;
	const char	*p_src;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	p_dst = dst;
	p_src = src;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		++i;
	}
	return (dst);
}
