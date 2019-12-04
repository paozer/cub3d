/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 16:17:53 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 12:54:27 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(str = malloc(sizeof(*str) * ft_strlen(s) + 1)))
		return (NULL);
	str[0] = 0;
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		++i;
	}
	str[i] = 0;
	return (str);
}
