/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_id.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 03:22:22 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/07 03:41:07 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_del_id(t_id *id)
{
	if (id != NULL)
	{
		if (id->width != NULL)
			free(id->width);
		if (id->precision != NULL)
			free(id->precision);
		if (id->type != NULL)
			free(id->type);
		free(id);
	}
}
