/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:30:49 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/18 19:05:32 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_buf(const char *s, int len)
{
	write(1, s, len);
	return (len);
}

int		parse_inner(const char *format, va_list list)
{
	char	*str;

	if (*format == 's')
	{
		str = va_arg(list, char *);
		write_buf(str, ft_strlen(str));
	}
	return (0);
}

int		parse_format(const char *format, va_list list)
{
	char	*cur_chr;
	int		res;

	res = 0;
	while ((cur_chr = ft_strchr(format, '%')))
	{
		res += write_buf(format, cur_chr - format);
		format = cur_chr + 1;
		if (*format)
			res += parse_inner(format, list);
	}
	if (*format)
		res += write_buf(format, ft_strlen(format));
	return (res);
}
