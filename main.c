/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:39:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/22 19:00:46 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("MY RESPONSE: \n");
	ft_printf("%-+25.65lldUPS\n", 3);


	printf("\nPRINTF RESPONSE: \n");
	printf("%-+25.65lld\n", (long long)3);
	return (0);
}
