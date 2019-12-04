/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 13:36:44 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 13:56:59 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*p_src;
	char		*p_dst;

	p_src = (const char *)src;
	p_dst = (char *)dst;
	if (p_dst < p_src)
		ft_memcpy(p_dst, p_src, len);
	else if (p_dst > p_src)
		while (len)
		{
			p_dst[len - 1] = p_src[len - 1];
			--len;
		}
	return (dst);
}
