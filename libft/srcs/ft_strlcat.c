/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 10:25:47 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/16 12:11:29 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	char	*p_src;

	j = 0;
	i = 0;
	p_src = (char *)src;
	while (i < size)
	{
		if (dst[i] == 0)
			break ;
		if (i == size - 1 && dst[i])
			return (size + ft_strlen(src));
		++i;
	}
	i = ft_strlen(dst);
	while (i + j < size - 1 && p_src[j] && 0 < size)
	{
		dst[i + j] = src[j];
		++j;
	}
	dst[i + j] = 0;
	if (size < i)
		return (size + ft_strlen(src));
	return (i + ft_strlen(src));
}
