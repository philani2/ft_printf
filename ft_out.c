/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ochayche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 20:39:11 by ochayche          #+#    #+#             */
/*   Updated: 2018/08/03 14:50:48 by bgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	choose conversions: % s S p d D i o O u U x X c C
*/

#include "ft_printf.h"

int		ft_out(t_flist *lst, va_list va)
{
	int		res;

	res = 0;
	if (lst->spec == '%')
		res = (ft_print_percent(lst, '%'));
	else if (lst->spec == 'c' || lst->spec == 'C')
		res = (ft_handler_char(lst, va_arg(va, void *)));
	else if (lst->spec == 's' || lst->spec == 'S')
		res = (ft_handler_str(lst, va_arg(va, void *)));
	else if (lst->spec == 'd' || lst->spec == 'i' || lst->spec == 'D')
		res = (ft_handler_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'u' || lst->spec == 'U')
		res = (ft_handler_unsigned_digit(lst, va_arg(va, void *)));
	else if (lst->spec == 'x' || lst->spec == 'X')
		res = (ft_handler_x(lst, va_arg(va, void *)));
	else if (lst->spec == 'o' || lst->spec == 'O')
		res = (ft_handler_o(lst, va_arg(va, void *)));
	else if (lst->spec == 'p')
		res = (ft_handler_ptr(lst, va_arg(va, void *)));
	else
		res = (ft_handler_char(lst, va_arg(va, void *)));
	ft_strdel(&(lst->flags));
	return (res);
}
