/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:35:43 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/08 19:03:49 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*pf_get_float(t_arg *args, va_list *list, int *len)
{
	char	*answer;
	char	*str;
	int		index;
	int		actlen;

	str = my_ftoa(va_arg(*list, double), args->precisn);
	actlen = ft_strlen(str);
	*len = args->width > actlen ? args->width : actlen;
	answer = ft_strnew(*len);
	ft_memset(answer, ' ', *len);
	index = args->flag.left_jstfed ? 0 : *len - actlen;
	if (args->precisn == 0 && args->flag.hash)
	{
		index--;
		*(answer + index + actlen) = '.';
	}
	ft_memcpy(answer + index, str, actlen);
	ft_strdel(&str);
	return (answer);
}
