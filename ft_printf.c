/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgumede <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 13:38:00 by bgumede           #+#    #+#             */
/*   Updated: 2018/08/09 14:12:15 by bgumede          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int						ft_printf(char *fmt, ...)
{
	int					len;
	va_list				va;

	len = 0;
	va_start(va, fmt);
	while (*fmt != '\0')
	{
		if (*fmt != '%')
			len += ft_print_char(*fmt);
		else
		{
			fmt++;
			len += ft_conversion(&(fmt), va);
		}
		fmt++;
	}
	va_end(va);
	return (len);
}
