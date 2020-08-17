/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_precision.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 17:29:19 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/21 16:26:31 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_precision(const char *str, t_id *id, int *pos)
{
	int		i;

	if (str[0] != '.')
		return (0);
	i = 1;
	while (str[i] != '\0' && (ft_isdigit((int)str[i]) || str[i] == '*'))
		i++;
	id->precision = ft_substr(str, 1, i - 1);
	*pos += i;
	return (i);
}
