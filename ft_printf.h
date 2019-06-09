/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eagulov <eagulov@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/16 13:18:25 by eagulov           #+#    #+#             */
/*   Updated: 2019/06/08 17:35:19 by eagulov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <wchar.h>

typedef union		u_value
{
	char			c;
	char			*str;
	intmax_t		sint;
	uintmax_t		uint;
}					t_value;


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
	int				precisn;
	char			*length;
	char			specifier;
	char			sign;
	int				len;
	t_flags			flag;
	t_value			val;
}					t_arg;

typedef	struct		s_metadata
{
	int				actlen;
	int				isneg;
	int				zeros;
	char			*value;
}					t_meta;



typedef char* (*t_func)(t_arg*, va_list*, int *len);

int					ft_printf(const char *format, ...);
int					construct(char **dest, int destlen, char *orig, int size);
int					check_format(char *format, va_list *list);
void				parse_flags(char **format, t_arg *args);
void				parse_width(char **format, t_arg *args, va_list *list);
void				parse_precisn(char **format, t_arg *args, va_list *list);
void				parse_length(char **format, t_arg *args);
void				parse_specifier(char **format, t_arg *args);
int					logic(va_list *list, t_arg *args, char **finalstr,
																int finallen);
char				*pf_get_float(t_arg *args, va_list *list, int *len);
char				*pf_get_number(t_arg *args, va_list *list, int *len);
char				*pf_get_unumber(t_arg *args, va_list *list, int *len);
char				*pf_get_char(t_arg *args, va_list *list, int *len);
char				*pf_get_str(t_arg *args, va_list *list, int *len);
char				*pf_get_wstr(t_arg *args, va_list *list, int *len);
char				*pf_get_octal(t_arg *args, va_list *list, int *len);
char				*pf_octal_wrapper(t_arg *args, va_list *list, int *len);
char				*pf_get_hex(t_arg *args, va_list *list, int *len);
char				*pf_hex_wrapper(t_arg *args, va_list *list, int *len);
char				*pf_get_addr(t_arg *args, va_list *list, int *len);
char				*pf_get_binary(t_arg *args, va_list *list, int *len);
void				conversion_sint(t_arg *args, va_list *list);
void				conversion_uint(t_arg *args, va_list *list);



#endif
