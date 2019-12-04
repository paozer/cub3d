/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 14:57:39 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 12:53:16 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_ncharsize(long n)
{
	size_t i;

	i = 0;
	if (n <= 0)
		++i;
	while (n)
	{
		++i;
		n /= 10;
	}
	return (i + 1);
}

static void		ft_catchar(char *str, char c)
{
	size_t i;

	i = ft_strlen(str);
	str[i] = c;
	str[++i] = 0;
}

static void		ft_rec_itoa(long nb, char *ptr)
{
	if (nb > 9)
		ft_rec_itoa(nb / 10, ptr);
	ft_catchar(ptr, (nb % 10) + '0');
}

char			*ft_itoa(int n)
{
	long	nb;
	size_t	size;
	char	*ptr;

	nb = n;
	size = ft_ncharsize(nb);
	if (!(ptr = malloc(sizeof(char) * size)))
		return (NULL);
	*ptr = 0;
	if (n < 0)
	{
		ft_catchar(ptr, '-');
		nb *= -1;
	}
	ft_rec_itoa(nb, ptr);
	ptr[size - 1] = 0;
	return (ptr);
}
