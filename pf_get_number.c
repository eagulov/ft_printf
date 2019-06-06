/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 18:16:17 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/27 18:31:32 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		get_sign(t_arg *args)
{
	if (args->flag.force_sign)
		args->sign = '+';
	else if (args->flag.space)
		args->sign = ' ';
	else if (args->val.sint < 0)
	{
		args->sign = '-';
		args->val.sint *= -1;
	}
}

static char		*get_precisn(t_arg *args)
{
	char	*precisn;
	int		pre_cpy;

	pre_cpy = args->precisn;
	if (args->precisn < args->len || args->precisn == 0)
		precisn = ft_strdup("");
	else
	{
		pre_cpy -= args->len;
		precisn = ft_strnew(pre_cpy);
		ft_memset(precisn, '0', pre_cpy);
	}
	return (precisn);
}

static char		*get_width(t_arg *args, int val)
{
	char *width;

	if (args->width < val)
		width = ft_strdup("");
	else
	{
		width = ft_strnew(args->width - val);
		if ((args->flag.zero && args->precisn == 0) &&
											!args->flag.left_jstfed)
			ft_memset(width, '0', args->width - val);
		else
			ft_memset(width, ' ', args->width - val);
	}
	return (width);
}

static void		pf_delextra(char **precisn, char **width, char **value)
{
	ft_memdel((void **)precisn);
	ft_memdel((void **)width);
	ft_memdel((void **)value);
}

char			*pf_get_number(t_arg *args, va_list *list, int *len)
{
	char	*precisn;
	char	*width;
	char	*value;
	char	*res;

	conversion_sint(args, list);
	get_sign(args);
	value = my_ltoa(args->val.sint, 10);
	*len = ft_strlen(value);
	precisn = get_precisn(args);
	*len = (args->precisn == -1 || args->precisn == -2) ? 0 : *len;
	width = get_width(args, ft_strlen(precisn) + *len +
									((args->sign != '\0') ? 1 : 0));
	if (args->flag.left_jstfed)
		res = my_strmjoin(4, &args->sign, precisn, value, width);
	else if ((args->precisn == -2 || args->precisn == -1) &&
												args->val.sint == 0)
		res = my_strmjoin(2, width, precisn);
	else if (*width == ' ')
		res = my_strmjoin(4, width, &args->sign, precisn, value);
	else
		res = my_strmjoin(4, &args->sign, width, precisn, value);
	*len = ft_strlen(res);
	pf_delextra(&precisn, &width, &value);
	return (res);
}
