/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:22:22 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/29 22:12:46 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_id(t_id **id)
{
	if (id != NULL && *id != NULL)
	{
		if ((*id)->width != NULL)
			ft_free((void**)&((*id)->width));
		if ((*id)->precision != NULL)
			ft_free((void**)&((*id)->precision));
		if ((*id)->type != NULL)
			ft_free((void**)&((*id)->type));
		ft_free((void**)id);
	}
}
