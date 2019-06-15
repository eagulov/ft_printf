/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:39:46 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/14 16:08:31 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			ret_bytes;
	char		*copy;
	va_list		list;

	va_start(list, format);
	copy = ft_strdup(format);
	ret_bytes = check_format(copy, &list);
	va_end(list);
	free(copy);
	return (ret_bytes);
}
