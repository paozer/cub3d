/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 12:48:23 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 12:52:54 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t		i;
	char		*p_dst;
	const char	*p_src;

	i = 0;
	p_dst = (char *)dst;
	p_src = (const char *)src;
	while (i < n)
	{
		p_dst[i] = p_src[i];
		if ((unsigned char)p_src[i] == (unsigned char)c)
			return (++p_dst + i);
		++i;
	}
	return (NULL);
}
