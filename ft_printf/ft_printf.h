/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:53:12 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/04 21:39:18 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

# define ID_TYPES		"cspdiuxX%"
# define ID_FLAGS		"-0 +"

# define FLG_MINUS		1
# define FLG_ZERO		2
# define FLG_SPACE		4
# define FLG_PLUS		8
# define FLG_HASH		16

# define FD_OUTPUT		1

# define BS_OCT			"01234567"
# define BS_DEC			"0123456789"
# define BS_HEX_LOW		"0123456789abcdef"
# define BS_HEX_UP		"0123456789ABCDEF"

typedef unsigned char	t_flag;

typedef struct			s_id
{
	t_flag				flags;
	size_t				length;
	char				*width;
	size_t				f_width;
	size_t				neg_1star;
	char				*precision;
	size_t				f_precision;
	size_t				neg_2star;
	char				*type;
}						t_id;

typedef struct			s_format
{
	const char			*input;
	char				*output;
	size_t				out_len;
	t_id				*id;
	va_list				*args;
}						t_format;

int						ft_printf(const char *fmt, ...);
int						ft_free(void **ptr);
t_format				*ft_new_fmt(const char *fmt, va_list *arg);
void					ft_del_fmt(t_format **fmt);
int						ft_build_output(t_format *fmt, int *it);
int						ft_concat_char(char **str, char c, size_t str_len);
int						ft_concat_str(char **s1, char **s2, size_t *s1_len,
											size_t s2_len);
t_id					*ft_new_id(const char *str);
int						ft_del_id(t_id **id);
int						ft_is_present(char c, const char *set);
int						ft_has_flag(t_id *id, t_flag flag);
int						ft_get_flag(const char *str, t_id *id, int *pos);
int						ft_get_width(const char *str, t_id *id, int *pos);
int						ft_get_precision(const char *str, t_id *id, int *pos);
int						ft_get_type(const char *str, t_id *id, int *pos);
int						ft_filter_id(t_format *fmt);
int						ft_process_arg(t_format *fmt);
int						ft_process_c(t_format *fmt);
int						ft_process_s(t_format *fmt);
int						ft_process_p(t_format *fmt);
int						ft_process_d(t_format *fmt);
int						ft_process_i(t_format *fmt);
int						ft_process_u(t_format *fmt);
int						ft_process_x(t_format *fmt);
int						ft_process_xu(t_format *fmt);
int						ft_process_pc(t_format *fmt);

#endif

/*
**		░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
**		░░░░░░░░░░▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄░░░░░░░░░
**		░░░░░░░░▄▀░░░░░░░░░░░░▄░░░░░░░▀▄░░░░░░░
**		░░░░░░░░█░░▄░░░░▄░░░░░░░░░░░░░░█░░░░░░░
**		░░░░░░░░█░░░░░░░░░░░░▄█▄▄░░▄░░░█░▄▄▄░░░
**		░▄▄▄▄▄░░█░░░░░░▀░░░░▀█░░▀▄░░░░░█▀▀░██░░
**		░██▄▀██▄█░░░▄░░░░░░░██░░░░▀▀▀▀▀░░░░██░░
**		░░▀██▄▀██░░░░░░░░▀░██▀░░░░░░░░░░░░░▀██░
**		░░░░▀████░▀░░░░▄░░░██░░░▄█░░░░▄░▄█░░██░
**		░░░░░░░▀█░░░░▄░░░░░██░░░░▄░░░▄░░▄░░░██░
**		░░░░░░░▄█▄░░░░░░░░░░░▀▄░░▀▀▀▀▀▀▀▀░░▄▀░░
**		░░░░░░█▀▀█████████▀▀▀▀████████████▀░░░░
**		░░░░░░████▀░░███▀░░░░░░▀███░░▀██▀░░░░░░
**		░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
*/
