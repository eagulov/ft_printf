/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:39:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/10 17:06:11 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	// printf("MY RESPONSE: \n");
	// ft_printf("|%-5c|\n",'b');
	// ft_printf("|%5c|\n",'b');
	// ft_printf("|%3c|\n",'b');
	// ft_printf("|%-c|\n",'b');
	// ft_printf("|%2c|\n",'b');
	// ft_printf("|%*c|\n", 4, 'b');
	// printf("\nPRINTF RESPONSE: \n");
	// printf("|%-5c|\n",'b');
	// printf("|%5c|\n",'b');
	// printf("|%3c|\n",'b');
	// printf("|%-c|\n",'b');
	// printf("|%2c|\n",'b');
	// printf("|%*c|\n", 4, 'b');

	// printf("MY RESPONSE: \n");
	// ft_printf("|%s|\n","abc");
	// ft_printf("|%4s|\n","abc");
	// ft_printf("|%-4s|\n","abc");
	// ft_printf("|%5.2s|\n","abc");
	// ft_printf("|%3.7s|\n","abc");
	// ft_printf("|%2s|\n", "abc");
	// printf("\nPRINTF RESPONSE: \n");
	// printf("|%s|\n","abc");
	// printf("|%4s|\n","abc");
	// printf("|%-4s|\n","abc");
	// printf("|%5.2s|\n","abc");
	// printf("|%3.7s|\n","abc");
	// printf("|%2s|\n", "abc");

	// printf("MY RESPONSE: \n");
	// ft_printf("|%x|\n",342);
	// ft_printf("|%#4x|\n", 342);
	// ft_printf("|%-#10X|\n",342);
	// ft_printf("|%-#10.7X|\n",342);
	// ft_printf("|%#3.1x|\n",342);
	// ft_printf("|%#2X|\n", 342);
	// printf("\nPRINTF RESPONSE: \n");
	// printf("|%x|\n",342);
	// printf("|%#4x|\n", 342);
	// printf("|%-#10X|\n",342);
	// printf("|%-#10.7X|\n",342);
	// printf("|%#3.1x|\n",342);
	// printf("|%#2X|\n", 342);

	// printf("MY RESPONSE: \n");
	// ft_printf("|%o|\n",342);
	// ft_printf("|%#4o|\n", 342);
	// ft_printf("|%-#10o|\n",342);
	// ft_printf("|%#5.5o|\n",342);
	// ft_printf("|%-#3.4o|\n",342);
	// ft_printf("|%#2O|\n", 342);
	// printf("\nPRINTF RESPONSE: \n");
	// printf("|%o|\n",342);
	// printf("|%#4o|\n", 342);
	// printf("|%-#10o|\n",342);
	// printf("|%#5.5o|\n",342);
	// printf("|%-#3.4o|\n",342);
	// printf("|%#2O|\n", 342);

	// printf("MY RESPONSE: \n");
	// ft_printf("|%+10.8d|\n", 54654);
	// ft_printf("|% -10d|\n", 54654);
	// ft_printf("|%5.3d|\n",54654);
	// ft_printf("|%-3.10d|\n",54654);
	// ft_printf("|%0 10i|\n", 54654);
	// ft_printf("|%-20.10d|\n",54654);
	// ft_printf("|%+20.1d|\n",54654);
	// ft_printf("|% *.*d|\n", 6, 6, 54654);
	// printf("\nPRINTF RESPONSE: \n");
	// printf("|%+10.8d|\n", 54654);
	// printf("|% -10d|\n", 54654);
	// printf("|%5.3d|\n",54654);
	// printf("|%-3.10d|\n",54654);
	// printf("|%0 10i|\n", 54654);
	// printf("|%-20.10d|\n",54654);
	// printf("|%+20.1d|\n",54654);
	// printf("|% *.*d|\n", 6, 6, 54654);

	// printf("MY RESPONSE: \n");
	// ft_printf("|%10.8u|\n", 54654);
	// ft_printf("|%-10u|\n", 54654);
	// ft_printf("|%5.3u|\n",54654);
	// ft_printf("|%-3.10u|\n",54654);
	// ft_printf("|%010u|\n", 54654);
	// ft_printf("|%-20.10u|\n",54654);
	// ft_printf("|%20.1u|\n",54654);
	// ft_printf("|%*.*u|\n", 6, 6, 54654);
	// printf("\nPRINTF RESPONSE: \n");
	// printf("|%10.8u|\n", 54654);
	// printf("|%-10u|\n", 54654);
	// printf("|%5.3u|\n",54654);
	// printf("|%-3.10u|\n",54654);
	// printf("|%010u|\n", 54654);
	// printf("|%-20.10u|\n",54654);
	// printf("|%20.1u|\n",54654);
	// printf("|%*.*u|\n", 6, 6, 54654);

	// void 	*memory;

	// memory = malloc(10);
	// printf("MY RESPONSE: \n");
	// ft_printf("|%p => %lu|\n", memory, (unsigned long)memory);
	// printf("\nPRINTF RESPONSE: \n");
	// printf("|%p => %lu|\n", memory, (unsigned long)memory);
	// ft_memdel(&memory);

	double e = 2.718281828;
	
	printf("MY RESPONSE: \n");
	ft_printf("|%5.1f|\n", e);
	ft_printf("|%-5.1f|\n", e);
	ft_printf("|%+5.1f|\n",e);
	ft_printf("|%+-5.1f|\n",e);
	ft_printf("|%05.1f|\n", e);
	ft_printf("|%+05.1f|\n",e);
	ft_printf("|% 05.1f|\n",e);
	ft_printf("|%- 5.1lf|\n", e);
	printf("\nPRINTF RESPONSE: \n");
	printf("|%5.1f|\n", e);
	printf("|%-5.1f|\n", e);
	printf("|%+5.1f|\n",e);
	printf("|%+-5.1f|\n",e);
	printf("|%05.1f|\n", e);
	printf("|%+05.1f|\n",e);
	printf("|% 05.1f|\n",e);
	printf("|%- 5.1lf|\n", e);

	// ft_printf("\nLOX\n");
	// ft_printf("|%b|\n", 42);
	// ft_printf("|%-10.10b|\n", 42);
	// ft_printf("|%5b|\n", 42);
	// ft_printf("|%3b|\n", 42);
	// ft_printf("|%20.12b|\n", 42);
	// ft_printf("|%7.3b|\n", 42);
	// ft_printf("|%-8.5b|\n", 42);
	// ft_printf("|%1b|\n", 42);
	

	printf("MY RESPONSE: \n");
	ft_printf("|%li|\n", 5);
	ft_printf("|%hhi|\n", 120);
	ft_printf("|%hi|\n", 120);
	ft_printf("|%li|\n", 123123123213);
	printf("\nPRINTF RESPONSE: \n");
	printf("|%li|\n", 5);
	printf("|%hhi|\n", 120);
	printf("|%hi|\n", 120);
	printf("|%li|\n", 123123123213);


	return (0);
}
