/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 02:39:22 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 16:22:56 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	*ft_new_fmt(const char *fmt, va_list *arg)
{
	t_format	*new_fmt;

	if (fmt == NULL || arg == NULL)
		return (NULL);
	new_fmt = (t_format*)ft_calloc(1, sizeof(t_format));
	if (new_fmt != NULL)
	{
		new_fmt->input = fmt;
		new_fmt->args = arg;
	}
	return (new_fmt);
}
