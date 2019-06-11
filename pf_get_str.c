/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 10:50:06 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/10 16:20:00 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_get_str(t_arg *args, va_list *list, int *len)
{
	char	*str;
	char	*answer;
	int		actlen;
	int		prec;

	str = va_arg(*list, char *);
	actlen = ft_strlen(str);
	*len = (actlen < args->width) ? args->width : actlen;
	answer = ft_strnew(*len);
	answer = ft_memset(answer, ' ', *len);
	prec = (args->precisn != -1 && args->precisn < actlen) ? \
			args->precisn : actlen;
	if (args->flag.left_jstfed)
		ft_strncpy(answer, str, prec);
	else
		ft_strncpy(answer + (*len - prec), str, prec);
	return (answer);
}
