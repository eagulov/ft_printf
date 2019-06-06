/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 11:21:56 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/25 20:56:17 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_sint(t_arg *args, va_list *list)
{
	if (args->length[0] == '\0')
		args->val.sint = va_arg(*list, int);
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		args->val.sint = (char)va_arg(*list, int);
	else if (args->length[0] == 'h')
		args->val.sint = (short int)va_arg(*list, int);
	else if (args->length[0] == 'l' && args->length[1] == 'l')
		args->val.sint = va_arg(*list, long long int);
	else if (args->length[0] == 'l')
		args->val.sint = va_arg(*list, long int);
	else if (args->length[0] == 'j')
		args->val.sint = va_arg(*list, intmax_t);
	else if (args->length[0] == 'z')
		args->val.sint = va_arg(*list, size_t);
}

void	conversion_uint(t_arg *args, va_list *list)
{
	if (args->specifier == 'U')
		args->val.uint = va_arg(*list, unsigned long int);
	else if (args->length[0] == '\0')
		args->val.uint = va_arg(*list, unsigned int);
	else if (args->length[0] == 'h' && args->length[1] == 'h')
		args->val.uint = (unsigned char)va_arg(*list, unsigned int);
	else if (args->length[0] == 'h')
		args->val.uint = (unsigned short)va_arg(*list, unsigned int);
	else if (args->length[0] == 'l' && args->length[1] == 'l')
		args->val.uint = va_arg(*list, unsigned long long int);
	else if (args->length[0] == 'l')
		args->val.uint = va_arg(*list, unsigned long int);
	else if (args->length[0] == 'j')
		args->val.uint = va_arg(*list, uintmax_t);
	else if (args->length[0] == 'z')
		args->val.uint = va_arg(*list, size_t);
}
