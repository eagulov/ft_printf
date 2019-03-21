/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:39:46 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/20 15:59:37 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			ret_bytes;
	va_list		list;

	va_start(list, format);
	ret_bytes = check_format(format, list);
	va_end(list);
	return (ret_bytes);
}
