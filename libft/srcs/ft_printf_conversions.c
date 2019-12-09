/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf_conversions.c                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/14 22:05:43 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 15:44:16 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		ft_char_conv(t_fields *flags, va_list *ap, int *ret)
{
	int				i;
	unsigned char	c;

	i = 0;
	c = va_arg(*ap, int);
	if (flags->wd_flag != -1)
	{
		if (flags->left_flag == 1)
			*ret += write(1, &c, 1);
		while (++i < flags->wd)
			*ret += write(1, " ", 1);
		if (flags->left_flag == -1)
			*ret += write(1, &c, 1);
		return ;
	}
	*ret += write(1, &c, 1);
}

static void	ft_str_conv2(t_fields *flags, char *str, int *ret)
{
	int i;
	int l;

	i = 0;
	l = ft_strlen(str);
	if (flags->left_flag == 1)
	{
		while ((flags->prc_flag == -1 || i < flags->prc) && str[i])
			*ret += write(1, &str[i++], 1);
		while (i++ < flags->wd && flags->wd != -1)
			*ret += write(1, " ", 1);
	}
	else if (flags->wd_flag == 1)
	{
		while (i++ < flags->wd - flags->prc &&
			(flags->wd > l || flags->wd > flags->prc))
			*ret += write(1, " ", 1);
		i = 0;
		while (str[i] && (i < flags->prc || flags->prc_flag == -1))
			*ret += write(1, &str[i++], 1);
	}
	else
		while ((flags->prc_flag == -1 || i < flags->prc) && str[i])
			*ret += write(1, &str[i++], 1);
}

void		ft_str_conv(t_fields *flags, va_list *ap, int *ret)
{
	int		l;
	char	*str;

	if (!(str = va_arg(*ap, char *)))
		str = NULL_STR;
	l = ft_strlen(str);
	flags->prc = (flags->prc_flag == -1 || l < flags->prc) ? l : flags->prc;
	flags->prc = (flags->prc_err_flag == 1) ? 0 : flags->prc;
	ft_str_conv2(flags, str, ret);
}

void		ft_ptr_conv(t_fields *flags, va_list *ap, int *ret)
{
	int		i;
	int		size;
	void	*ptr;
	long	addr;

	i = 0;
	ptr = va_arg(*ap, void *);
	addr = (long)ptr;
	size = ft_unbr_base_size(addr, 16) + 2;
	if (flags->prc_err_flag == 1 && !addr)
		size = 2;
	*ret += size;
	while (++i < flags->wd - size + 1 && flags->left_flag == -1)
		*ret += write(1, " ", 1);
	write(1, "0x", 2);
	if (flags->prc_err_flag == 1 && !addr)
		return ;
	ft_putunbr_base(addr, "0123456789abcdef", 16);
	while (++i < flags->wd - size + 2 && flags->left_flag == 1)
		*ret += write(1, " ", 1);
}

void		ft_mod_conv(t_fields *flags, int *ret)
{
	int i;

	i = 0;
	if (flags->left_flag == 1)
		*ret += write(1, "%", 1);
	while (i < flags->wd - 1 && flags->zero_flag == -1)
	{
		++i;
		*ret += write(1, " ", 1);
	}
	while (i < flags->wd - 1 && flags->zero_flag == 1)
	{
		++i;
		*ret += write(1, "0", 1);
	}
	if (flags->left_flag == -1)
		*ret += write(1, "%", 1);
}
