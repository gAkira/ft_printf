/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 03:37:21 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/09 17:36:45 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_fmt(t_format *fmt)
{
	if (fmt != NULL)
	{
		if (fmt->output != NULL)
			free(fmt->output);
		if (fmt->id != NULL)
			ft_del_id(fmt->id);
		if (fmt->args != NULL)
			va_end(*(fmt->args));
		free(fmt);
	}
}
