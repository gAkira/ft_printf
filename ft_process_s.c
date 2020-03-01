/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:35 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/29 20:33:22 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_arg(t_format *fmt)
{
	char	*arg;

	arg = va_arg(*(fmt->args), char*);
	if (arg == NULL)
		return (ft_strdup("(null)"));
	return (ft_strdup(arg));
}

int			ft_process_s(t_format *fmt)
{
	size_t	o_len;
	size_t	a_len;
	char	*new_o;
	char	*arg;

	arg = get_arg(fmt);
	a_len = ft_strlen(arg);
	o_len = a_len;
	if (fmt->id->precision && !fmt->id->neg_2star)
		a_len = fmt->id->f_precision < o_len ? fmt->id->f_precision : o_len;
	if (fmt->id->width)
		o_len = fmt->id->f_width > a_len ? fmt->id->f_width : a_len;
	if (!(new_o = (char*)ft_calloc(o_len + 1, sizeof(char))))
		return (0);
	ft_memset(new_o, ' ', o_len);
	if (ft_has_flag(fmt->id, FLG_MINUS))
		ft_memcpy(new_o, arg, a_len);
	else
		ft_memcpy(&new_o[o_len - a_len], arg, a_len);
	if (ft_has_flag(fmt->id, FLG_ZERO) && !ft_has_flag(fmt->id, FLG_MINUS))
		ft_memset(new_o, '0', o_len - a_len);
	if (!ft_concat_str(&(fmt->output), new_o, &(fmt->out_len), o_len))
		return (0);
	return (42);
}
