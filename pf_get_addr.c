/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:29:55 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/07 17:39:05 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*pf_get_addr(t_arg *args, va_list *list, int *len)
{
	char	*str;
	char	*answer;

	if (args)
		;
	str = my_ltoa(va_arg(*list, unsigned long), 16);
	*len = ft_strlen(str) + 2;
	answer = ft_strnew(*len);
	answer = ft_strncpy(answer, "0x", 2);
	ft_memcpy(answer + 2, str, *len - 2);
	ft_strdel(&str);
	return (my_strlower(answer));
}
