/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:53:12 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/01 09:35:28 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdargs.h>

# define ID_TYPES		"cspdiuxX%"
# define ID_FLAGS		"-0 +"

# define FLG_MINUS		1
# define FLG_ZERO		2
# define FLG_SPACE		4
# define FLG_PLUS		8
# define FLG_HASH		16

# define FD_OUTPUT		1

typedef unsigned char	t_flag;

typedef struct			s_id
{
	t_flag				flags;
	size_t				length;
	char				*width;
	char				*precision;
	char				*type;
}						t_id;

typedef struct			s_format
{
	const char			*input;
	char				*output;
	t_id				*id;
	va_list				*args;
}						t_format;

int						ft_printf(const char *fmt, ...);
t_format				*ft_new_fmt(const char *fmt, va_list *arg);
void					ft_del_fmt(t_format *fmt);
int						ft_build_output(t_format *fmt, int *it);
int						ft_putstr_output(t_format *fmt, char *str);
int						ft_putchar_output(t_format *fmt, char c);
t_id					*ft_new_id(const char *str);

char					*ft_itoa_base(int nbr, const char *base);

#endif
