/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_unumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 20:23:49 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/27 18:32:46 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*get_precisn(t_arg *args)
{
	char	*precisn;

	if (args->precisn < args->len || args->precisn == 0)
		precisn = ft_strdup("");
	else
	{
		args->precisn -= args->len;
		precisn = ft_strnew(args->precisn);
		ft_memset(precisn, '0', args->precisn);
	}
	return (precisn);
}

static char		*get_width(t_arg *args, int val)
{
	char	*width;

	if (args->width < val)
		width = ft_strdup("");
	else
	{
		width = ft_strnew(args->width - val);
		if (args->flag.zero && args->precisn == 0 && !args->flag.left_jstfed)
			ft_memset(width, '0', args->width - val);
		else
			ft_memset(width, ' ', args->width - val);
	}
	return (width);
}

char			*pf_get_unumber(t_arg *args, va_list *list, int *len)
{
	char	*precisn;
	char	*width;
	char	*value;
	char	*res;

	conversion_uint(args, list);
	value = my_ltoa(args->val.uint, 10);
	*len = ft_strlen(value);
	precisn = get_precisn(args);
	*len = (args->precisn == -1 || args->precisn == -2) ? 0 : *len;
	width = get_width(args, ft_strlen(precisn) + *len +
										((args->sign != '\0') ? 1 : 0));
	if (args->flag.left_jstfed)
		res = my_strmjoin(3, precisn, value, width);
	else if ((args->precisn == -2 || args->precisn == -1) &&
													args->val.uint == 0)
		res = my_strmjoin(2, width, precisn);
	else
		res = my_strmjoin(3, width, precisn, value);
	*len = ft_strlen(res);
	ft_memdel((void **)&precisn);
	ft_memdel((void **)&width);
	ft_memdel((void **)&value);
	return (res);
}
