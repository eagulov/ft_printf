/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_binary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 07:57:50 by eagulov           #+#    #+#             */
/*   Updated: 2019/05/27 18:30:41 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_get_binary(t_arg *args, va_list *list, int *len)
{
	char	*res;

	conversion_uint(args, list);
	res = my_get_binary(args->val.uint);
	*len = ft_strlen(res);
	return (res);
}
