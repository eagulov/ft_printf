/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:30:49 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/22 19:05:07 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		write_buf(const char *s, int len)
{
	write(1, s, len);
	return (len);
}

t_arg		*my_argnew(void)
{
	t_arg	*new;

	new = (t_arg *)ft_memalloc(sizeof(t_arg));
	new->width = 0;
	new->precision = 0;
	new->length = ft_strnew(0);
	return (new);
}

// int		parse_format(const char *format, va_list list)
// {
// 	char	*str;
// 	int		num;
// 	int		res;

// 	if (*format == 's')
// 	{
// 		str = va_arg(list, char *);
// 		res = write_buf(str, ft_strlen(str));
// 	}
// 	if (*format == 'd')
// 	{
// 		num = va_arg(list, int);
// 		str = ft_itoa(num);
// 		res = write_buf(str, ft_strlen(str));
// 	}
// 	if (*format == ' ')
// 	{
		
// 	}
// 	return (res);
// }

int		parse_format(char **format, va_list *list)
{
	t_arg	*args;

	args = my_argnew();
	parse_flags(format, args);
	parse_width(format, args, list);
	parse_precision(format, args, list);
	parse_length(format, args);
	parse_specifier(format, args);
	return (0);
}

int		check_format(char *format, va_list *list)
{
	char	*cur_char;
	int		res;

	res = 0;
	while ((cur_char = ft_strchr(format, '%')))
	{
		res += write_buf(format, cur_char - format);
		format = cur_char + 1;
		if (*format)
			res += parse_format(&format, list);
	}
	if (*format)
		res += write_buf(format, ft_strlen(format));
	return (res);
}
