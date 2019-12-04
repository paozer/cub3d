/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/08 16:34:50 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/14 15:56:12 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *str;

	str = (char *)s;
	if (c == 0)
		return (str + ft_strlen(str));
	while (*str)
	{
		if (*str == c)
			return (str);
		++str;
	}
	return (NULL);
}
