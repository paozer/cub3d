/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: pramella <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 16:50:02 by pramella     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/09 15:42:48 by pramella    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# define NULL_STR "(null)"

typedef struct	s_fields
{
	int			zero_flag;
	int			left_flag;
	int			wd_flag;
	int			wd;
	int			prc_flag;
	int			prc_err_flag;
	int			prc;
	char		type;
	size_t		end;
}				t_fields;

typedef struct	s_nbr
{
	long		value;
	int			unsigned_flag;
	int			len;
	char		*base;
}				t_nbr;

int				ft_printf(const char *fmt, ...)
 __attribute__((format(printf,1,2)));
t_fields		*ft_format_setup(char *fmt, va_list *ap);

void			ft_char_conv(t_fields *flags, va_list *ap, int *ret);
void			ft_str_conv(t_fields *flags, va_list *ap, int *ret);
void			ft_ptr_conv(t_fields *flags, va_list *ap, int *ret);
void			ft_mod_conv(t_fields *flags, int *ret);

void			ft_dec_conv(t_fields *flags, va_list *ap, int *ret);
void			ft_dec_helper(t_fields *flags, t_nbr *nbr);
void			ft_dec_relayer(t_fields *flags, t_nbr *nbr, int *ret);

void			ft_putnbr_base(long nbr, char *base, int base_len);
void			ft_putunbr_base(unsigned long nbr, char *base, int base_len);
int				ft_unbr_base_size(unsigned long nbr, int base_len);
int				ft_nbr_base_size(long nbr, int base_len);

#endif
