/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 17:35:43 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/14 15:53:16 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char				*pf_get_float(t_arg *ar, va_list *list, int *len)
{
	char	*answer;
	char	*str;
	int		index;
	int		actlen;

	str = my_ftoa(va_arg(*list, double), ar->precisn);
	actlen = ft_strlen(str);
	*len = ar->width > actlen ? ar->width : actlen;
	answer = ft_strnew(*len);
	ft_memset(answer, ar->flag.zero && !ar->flag.left_jstfed ? '0' : ' ', *len);
	index = ar->flag.left_jstfed ? 0 : *len - actlen;
	if ((ar->flag.force_sign || ar->flag.space) && str[0] != '-')
	{
		index -= (!ar->flag.zero && index - 1 > 0) ? 1 : 0;
		answer[ar->flag.zero ? 0 : index++] = ar->flag.force_sign ? '+' : ' ';
	}
	if (ar->precisn == 0 && ar->flag.hash)
		*(answer + (--index) + actlen) = '.';
	ft_memcpy(answer + index, str, actlen);
	ft_strdel(&str);
	return (answer);
}
