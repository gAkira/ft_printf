/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:35 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 19:04:20 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_process_s(t_format *fmt)
{
	size_t	len;
	size_t	a_len;
	char	*new_o;
	char	*arg;

	arg = ft_strdup(va_arg(*(fmt->args), char*));
	a_len = fmt->id->f_precision < ft_strlen(arg) ? fmt->id->f_precision :
				ft_strlen(arg);
	len = a_len;
	if (fmt->id->f_width > len)
		len = fmt->id->f_width > len ? fmt->id->f_width : len;
	if (!(new_o = (char*)ft_calloc(len + 1, sizeof(char))))
		return (0);
	ft_memset(new_o, ' ', len);
	if (ft_has_flag(fmt->id, FLG_MINUS))
		new_o[0] = (char)va_arg(*(fmt->args), int);
	else
		new_o[len - 1] = (char)va_arg(*(fmt->args), int);
	if (!ft_concat_str(&(fmt->output), new_o, &(fmt->out_len), len))
	{
		ft_free((void**)&new_o);
		return (0);
	}
	return (42);
}
