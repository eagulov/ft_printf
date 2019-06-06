/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 14:39:20 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/05 23:20:35 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("MY RESPONSE: \n");
	ft_printf("|%-5c|\n",'b');
	ft_printf("|%5c|\n",'b');
	ft_printf("|%3c|\n",'b');
	ft_printf("|%-c|\n",'b');
	ft_printf("|%2c|\n",'b');
	ft_printf("|%*c|\n", 4, 'b');
	printf("\nPRINTF RESPONSE: \n");
	printf("|%-5c|\n",'b');
	printf("|%5c|\n",'b');
	printf("|%3c|\n",'b');
	printf("|%-c|\n",'b');
	printf("|%2c|\n",'b');
	printf("|%*c|\n", 4, 'b');

	printf("MY RESPONSE: \n");
	ft_printf("|%s|\n","abc");
	ft_printf("|%4s|\n","abc");
	ft_printf("|%-4s|\n","abc");
	ft_printf("|%5.2s|\n","abc");
	ft_printf("|%3.7s|\n","abc");
	ft_printf("|%2s|\n", "abc");
	printf("\nPRINTF RESPONSE: \n");
	printf("|%s|\n","abc");
	printf("|%4s|\n","abc");
	printf("|%-4s|\n","abc");
	printf("|%5.2s|\n","abc");
	printf("|%3.7s|\n","abc");
	printf("|%2s|\n", "abc");

	printf("MY RESPONSE: \n");
	ft_printf("|%x|\n",342);
	ft_printf("|%#4x|\n", 342);
	ft_printf("|%-#10X|\n",342);
	ft_printf("|%-#10.7X|\n",342);
	ft_printf("|%#3.1x|\n",342);
	ft_printf("|%#2X|\n", 342);
	printf("\nPRINTF RESPONSE: \n");
	printf("|%x|\n",342);
	printf("|%#4x|\n", 342);
	printf("|%-#10X|\n",342);
	printf("|%-#10.7X|\n",342);
	printf("|%#3.1x|\n",342);
	printf("|%#2X|\n", 342);

	printf("MY RESPONSE: \n");
	ft_printf("|%o|\n",342);
	ft_printf("|%#4o|\n", 342);
	ft_printf("|%-#10o|\n",342);
	ft_printf("|%#5.5o|\n",342);
	ft_printf("|%-#3.4o|\n",342);
	ft_printf("|%#2O|\n", 342);
	printf("\nPRINTF RESPONSE: \n");
	printf("|%o|\n",342);
	printf("|%#4o|\n", 342);
	printf("|%-#10o|\n",342);
	printf("|%#5.5o|\n",342);
	printf("|%-#3.4o|\n",342);
	printf("|%#2O|\n", 342);



	return (0);
}
