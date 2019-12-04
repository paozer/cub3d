/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 12:53:57 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/15 18:16:07 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_getstart(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && ft_strchr(set, s1[i]))
		++i;
	return (i);
}

static size_t	ft_getend(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;

	i = 0;
	end = 0;
	while (s1[i])
	{
		if (!(ft_strchr(set, s1[i])))
			end = i;
		++i;
	}
	return (end);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*str;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = ft_getstart(s1, set);
	end = ft_getend(s1, set);
	if (end < start)
		return (ft_calloc(1, 1));
	if (!(str = malloc(sizeof(*str) * (end - start + 2))))
		return (NULL);
	ft_strlcpy(str, s1 + start, end - start + 2);
	return (str);
}
