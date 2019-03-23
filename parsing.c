/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:24:17 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/22 19:10:48 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_specifier(char **format, t_arg *args)
{
	args->specifier = **format;
	(*format)++;
}

void	parse_length(char **format, t_arg *args)
{
	char	*first_length;

	first_length = *format;
	while (**format == 'l' || **format == 'h' ||
			**format == 'j' || **format == 'z')
		(*format)++;
	args->length = ft_strsub(first_length, 0, *format - first_length);
}

void	parse_precision(char **format, t_arg *args, va_list *list)
{
	if (**format != '.')
		return ;
	else
		(*format)++;
	if (**format == '*')
	{
		args->precision = va_arg(*list, int);
		(*format)++;
	}
	else
		args->precision = ft_atoi(*format);
	while ((**format >= '0' && **format <= '9')
			|| **format == '+' || **format == '-')
		(*format)++;
}

void	parse_width(char **format, t_arg *args, va_list *list)
{
	if (**format == '*')
	{
		args->width = va_arg(*list, int);
		(*format)++;
	}
	else
		args->width = ft_atoi(*format);
	while (**format >= '0' && **format <= '9')
		(*format)++;
}

void	parse_flags(char **format, t_arg *args)
{
	while (**format == ' ' || **format == '#' || **format == '0'
						|| **format == '-' || **format == '+')
	{
		if (**format == ' ')
			args->flag.space = true;
		if (**format == '#')
			args->flag.hash = true;
		if (**format == '0')
			args->flag.zero = true;
		if (**format == '-')
			args->flag.left_jstfed = true;
		if (**format == '+')
			args->flag.force_sign = true;
		(*format)++;
	}
}
