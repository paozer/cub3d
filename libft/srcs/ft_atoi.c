/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_atoi.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 18:11:06 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/05 15:46:26 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int sign;
	int nb;

	i = 0;
	sign = -1;
	nb = 0;
	while (ft_isspace(str[i]))
		++i;
	if (str[i] == '+')
		++i;
	else if (str[i] == '-')
	{
		sign *= -1;
		++i;
	}
	while (ft_isdigit(str[i]))
	{
		nb = nb * 10 - (str[i] - '0');
		++i;
	}
	return (sign * nb);
}
