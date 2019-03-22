/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:24:17 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/21 17:45:39 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_precision(char **format, t_arg *args, va_list *list)
{
	char	*precision;

	precision = *format;
	if (*precision != '.')
		return ;
	else
		precision++;
	while ((precision >= '0' && precision <= '9')
			|| precision == '+' || precision == '-')
		precision++;
}




void	parse_width(char **format, t_arg *args, va_list *list)
{
	char	*width;

	width = *format;
	if (*width == '*')
	{
		args->width = va_arg(*list, int);
		width++;
	}
	else
		args->width = ft_atoi(*format);
	while (*width >= '0' && *width <= '9')
		width++;
	(*format) = width;
}

void	parse_flags(char **format, t_arg *args)
{
	char	*flag;

	flag = *format;
	while (*flag == ' ' || *flag == '#' || *flag == '0'
						|| *flag == '-' || *flag == '+')
	{
		if (*flag == ' ')
			args->flag.space = true;
		if (*flag == '#')
			args->flag.hash = true;
		if (*flag == '0')
			args->flag.zero = true;
		if (*flag == '-')
			args->flag.left_jstfed = true;
		if (*flag == '+')
			args->flag.force_sign = true;
		flag++;
	}
	(*format) = flag;
}
