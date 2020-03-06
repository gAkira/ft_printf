/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_fmt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 03:37:21 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 17:53:40 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_fmt(t_format **fmt)
{
	if (fmt != NULL && *fmt != NULL)
	{
		if ((*fmt)->output != NULL)
			ft_free((void**)&((*fmt)->output));
		if ((*fmt)->id != NULL)
			ft_del_id(&((*fmt)->id));
		if ((*fmt)->args != NULL)
			va_end(*((*fmt)->args));
		ft_free((void**)fmt);
	}
}
