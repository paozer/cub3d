/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/09 13:15:30 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/09 16:53:22 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	size_needle;
	char	*p_haystack;

	i = 0;
	p_haystack = (char *)haystack;
	if (needle[0] == 0)
		return (p_haystack);
	size_needle = ft_strlen(needle);
	while (p_haystack[i] && (i + size_needle - 1 < len))
	{
		if (p_haystack[i] == needle[0])
		{
			if (ft_strncmp((p_haystack + i), needle, size_needle) == 0)
				return (p_haystack + i);
		}
		++i;
	}
	return (0);
}
