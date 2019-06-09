/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 11:49:58 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/07 00:11:41 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_fill_data(char *dest, t_arg *args, int zeros, char *src)
{
	if (args->flag.hash)
		dest = ft_strncpy(dest, "0x", 2) + 2;
	while (zeros--)
		*dest++ = '0';
	dest = ft_strncpy(dest, src, ft_strlen(src));
}

char		*pf_get_hex(t_arg *args, va_list *list, int *len)
{
	char	*str;
	char	*answer;
	int		actlen;
	int		zeros;

	str = my_ltoa(va_arg(*list, unsigned long), 16);
	actlen = ft_strlen(str);
	zeros = args->precisn < actlen ? 0 : args->precisn - actlen;
	actlen += (args->flag.hash ? 2 : 0) + zeros;
	*len = args->width < actlen ? actlen : args->width;
	answer = ft_strnew(*len);
	answer = ft_memset(answer, ' ', *len);
	if (args->flag.left_jstfed)
		pf_fill_data(answer, args, zeros, str);
	else
		pf_fill_data(answer + (*len - actlen), args, zeros, str);
	ft_strdel(&str);
	return (answer);
}

char		*pf_hex_wrapper(t_arg *args, va_list *list, int *len)
{
	return (my_strupper(pf_get_hex(args, list, len)));
}
