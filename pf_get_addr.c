/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 08:29:55 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/27 18:30:21 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_prefix_postfix(t_arg *args)
{
	char	*res;
	int		num;

	num = args->width - args->len;
	num = (num < 0) ? 0 : num;
	res = ft_strnew(num);
	if (args->flag.zero)
		ft_memset(res, '0', num);
	else
		ft_memset(res, ' ', num);
	return (res);
}

char		*pf_get_addr(t_arg *args, va_list *list, int *len)
{
	char	*value;
	char	*prefix_postfix;
	char	*res;

	args->val.uint = va_arg(*list, unsigned long int);
	value = my_strmjoin(2, "0x", my_dectohex(args->val.uint));
	*len = ft_strlen(value);
	prefix_postfix = get_prefix_postfix(args);
	if (args->flag.left_jstfed || *prefix_postfix == '0')
		res = my_strmjoin(2, value, prefix_postfix);
	else
		res = my_strmjoin(2, prefix_postfix, value);
	*len = ft_strlen(res);
	return (res);
}
