/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:18:25 by eagulov           #+#    #+#             */
/*   Updated: 2019/03/22 19:00:00 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>

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
	char			specifier;
	t_flags			flag;
}					t_arg;

int					ft_printf(const char *format, ...);
int					check_format(char *format, va_list *list);
void				parse_flags(char **format, t_arg *args);
void				parse_width(char **format, t_arg *args, va_list *list);
void				parse_precision(char **format, t_arg *args, va_list *list);
void				parse_length(char **format, t_arg *args);
void				parse_specifier(char **format, t_arg *args);

#endif
