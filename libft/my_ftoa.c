/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:52:39 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/08 18:57:18 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*my_ftoa(long double number, int precisn)
{
	char	*str;
	char	*answer;
	int		intprtsize;

	intprtsize = my_nbsize((long long int)number);
	if (!precisn && ((long long int)(number * 10) % 10) >= 5)
		number++;
	while (precisn--)
		number *= 10;
	if ((long long int)number % 10 >= 5)
		((long long int)number > 0) ? number++ : number--;
	str = my_ltoa((long long int)number, 10);
	answer = ft_strnew(my_nbsize((long long int)number) + 1);
	ft_memcpy(answer, str, intprtsize);
	if (ft_strlen(str + intprtsize))
		answer[intprtsize] = '.';
	ft_memcpy(answer + intprtsize + 1, str + intprtsize,
												ft_strlen(str + intprtsize));
	ft_strdel(&str);
	return (answer);
}
