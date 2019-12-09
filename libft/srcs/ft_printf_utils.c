/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_utils.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/13 15:19:59 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 15:44:40 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putunbr_base(unsigned long nbr, char *base, int base_len)
{
	if (nbr >= (unsigned long)base_len)
		ft_putnbr_base(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

void	ft_putnbr_base(long nbr, char *base, int base_len)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= (long)base_len)
		ft_putnbr_base(nbr / base_len, base, base_len);
	write(1, &base[nbr % base_len], 1);
}

int		ft_unbr_base_size(unsigned long nbr, int base_len)
{
	if (nbr >= (unsigned long)base_len)
		return (1 + ft_nbr_base_size(nbr / base_len, base_len));
	return (1);
}

int		ft_nbr_base_size(long nbr, int base_len)
{
	nbr *= (nbr < 0) ? -1 : 1;
	if (nbr >= base_len)
		return (1 + ft_nbr_base_size(nbr / base_len, base_len));
	return (1);
}

void	ft_dec_helper(t_fields *flags, t_nbr *nbr)
{
	if (ft_strchr("diu", flags->type))
	{
		nbr->unsigned_flag = (flags->type != 'u') ? 0 : 1;
		if (nbr->unsigned_flag == 1)
			nbr->len = ft_unbr_base_size(nbr->value, 10);
		else
			nbr->len = ft_nbr_base_size(nbr->value, 10);
		nbr->base = ft_strdup("0123456789");
	}
	else
	{
		nbr->unsigned_flag = 1;
		nbr->len = ft_unbr_base_size(nbr->value, 16);
		nbr->base = NULL;
		if (flags->type == 'x')
			nbr->base = ft_strdup("0123456789abcdef");
		else if (flags->type == 'X')
			nbr->base = ft_strdup("0123456789ABCDEF");
	}
}
