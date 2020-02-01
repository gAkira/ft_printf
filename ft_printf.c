/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 01:56:46 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/01 09:34:20 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	int			itr;
	int			length;
	va_list		args;
	t_format	*fmt;

	itr = 0;
	va_start(args, format);
	fmt = ft_new_fmt(format, args);
	if (fmt != NULL && ft_build_output(fmt, &itr))
	{
		ft_putstr_fd(fmt->output, FD_OUTPUT);
		length = ft_strlen(fmt->output);
		ft_del_fmt(fmt);
		return (length);
	}
	return (-42);
}
