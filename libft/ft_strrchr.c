/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 16:44:09 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 14:57:14 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*p_s;

	i = ft_strlen(s) - 1;
	p_s = (char *)s;
	if (c == 0)
		return (p_s + i + 1);
	if (p_s[0] == c)
		return (p_s);
	while (0 < i)
	{
		if (p_s[i] == c)
			return (p_s + i);
		--i;
	}
	return (NULL);
}
