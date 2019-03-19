/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:39:46 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/18 18:50:19 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(char *format, ...)
{
	int			ret_bytes;
	va_list		list;

	va_start(list, format);
	ret_bytes = parse_format(format, list);
	va_end(list);
	return (ret_bytes);
}
