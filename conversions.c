/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:21:56 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/10 16:09:04 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long			conversion_signed(t_arg *args, va_list *list)
{
	long long int	value;

	value = va_arg(*list, long long int);
	if (args->length[0] == '\0')
		return (value);
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		value = (char)value;
	else if (args->length[0] == 'h')
		value = (short int)value;
	else if (args->length[0] == 'l')
		value = (long int)value;
	else if (args->length[0] == 'j')
		value = (intmax_t)value;
	else if (args->length[0] == 'z')
		value = (size_t)value;

	return (value);
}

unsigned long	conversion_unsigned(t_arg *args, va_list *list)
{
	unsigned long long int	value;

	value = va_arg(*list, unsigned long long int);
	if (args->length[0] == '\0')
		return (value);
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		value = (unsigned char)value;
	else if (args->length[0] == 'h')
		value = (unsigned short int)value;
	else if (args->length[0] == 'l')
		value = (unsigned long int)value;
	else if (args->length[0] == 'j')
		value = (uintmax_t)value;
	else if (args->length[0] == 'z')
		value = (size_t)value;
	return (value);
}
