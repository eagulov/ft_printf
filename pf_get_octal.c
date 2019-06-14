/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_get_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/26 09:11:48 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/13 15:15:24 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_fill_data(char *dest, t_arg *args, int zeros, char *src)
{
	if (args->flag.hash)
		dest = ft_strncpy(dest, "0", 1) + 1;
	while (zeros--)
		*dest++ = '0';
	if (*src == '0' && !args->precisn)
		return ;
	dest = ft_strncpy(dest, src, ft_strlen(src));
}

char			*pf_get_octal(t_arg *args, va_list *list, int *len)
{
	char	*str;
	char	*answer;
	int		actlen;
	int		zeros;

	str = my_ltoa(conversion_unsigned(args, list), 8);
	actlen = (*str == '0' && !args->width && !args->precisn) ? 0 : ft_strlen(str);
	zeros = args->precisn < actlen ? 0 : args->precisn - actlen;
	actlen += ((args->flag.hash) ? 1 : 0) + zeros;
	*len = args->width < actlen ? actlen : args->width;
	if (args->flag.zero && !args->flag.left_jstfed)
		zeros = *len - actlen;
	answer = ft_strnew(*len);
	answer = ft_memset(answer, ' ', *len);
	if (args->flag.left_jstfed || args->flag.zero)
		pf_fill_data(answer, args, zeros, str);
	else
		pf_fill_data(answer + (*len - actlen), args, zeros, str);
	ft_strdel(&str);
	return (answer);
}

char			*pf_octal_wrapper(t_arg *args, va_list *list, int *len)
{
	return (my_strupper(pf_get_octal(args, list, len)));
}
