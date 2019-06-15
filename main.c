/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 17:20:59 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/14 17:55:48 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

int 	main()
{

	// ft_printf("%u\n", 0);
	// printf("%u\n", 0);

	// printf("{%5p}\n", 0);
	// ft_printf("{%5p}\n", 0);

	printf("{%f}{%F}\n", -1.42, -1.42);
	ft_printf("{%f}{%F}\n", -1.42, -1.42);

// UNDEFINED BEHAVIOUR
	// printf("{%05.c}\n", 0);
	// ft_printf("{%05.c}\n", 0);

// UNDEFINED BEHAVIOUR
	// printf("{%05.s}\n", 0);
	// ft_printf("{%05.s}\n", 0);

	// printf("{%05.%}\n", 0);
	// ft_printf("{%05.%}\n", 0);

	printf("{%#.5x}\n", 1);
	ft_printf("{%#.5x}\n", 1);

	printf("{%#.3o}\n", 1);
	ft_printf("{%#.3o}\n", 1);


	return (0);
}