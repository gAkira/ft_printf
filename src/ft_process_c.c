/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:35 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/29 21:53:58 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_process_c(t_format *fmt)
{
	size_t	len;
	char	*new_o;

	len = fmt->id->f_width > 1 ? fmt->id->f_width : 1;
	if (!(new_o = (char*)ft_calloc(len + 1, sizeof(char))))
		return (0);
	ft_memset(new_o, ' ', len);
	if (ft_has_flag(fmt->id, FLG_MINUS))
		new_o[0] = (char)va_arg(*(fmt->args), int);
	else
		new_o[len - 1] = (char)va_arg(*(fmt->args), int);
	if (!ft_concat_str(&(fmt->output), &new_o, &(fmt->out_len), len))
	{
		ft_free((void**)&new_o);
		return (0);
	}
	ft_free((void**)&new_o);
	return (42);
}