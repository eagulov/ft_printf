/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:24:17 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/20 21:10:08 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	parse_flags(const char *format, t_arg *args)
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
	(*format) = (flag == *format) ? *format : flag;
}
