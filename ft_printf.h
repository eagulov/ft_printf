/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:18:25 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/20 21:11:14 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

# define BUFFSIZE	1000

typedef struct		s_flags
{
	bool			left_jstfed;
	bool			zero;
	bool			hash;
	bool			force_sign;
	bool			space;
}					t_flags;

typedef struct		s_arg
{
	int				width;
	int				precision;
	char			*length;
	t_flags			flag;
}					t_arg;

int					check_format(const char *format, va_list list);
int					ft_printf(const char *format, ...);
void				parse_flags(const char *format, t_arg *args);
void				parse_width(const char *format, t_arg *args, va_list *list);


#endif
