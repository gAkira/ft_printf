/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_type.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 04:28:50 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 16:37:07 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_type(const char *str, t_id *id, int *pos)
{
	if ((str[0] == 'l' || str[0] == 'h') && (str[1] == str[0]))
	{
		id->type = ft_substr(str, 0, 2);
		if (id->type != NULL)
		{
			(*pos) += 2;
			return (42);
		}
	}
	else if (ft_is_present(str[0], ID_TYPES))
	{
		id->type = ft_substr(str, 0, 1);
		if (id->type != NULL)
		{
			(*pos)++;
			return (42);
		}
	}
	return (0);
}
