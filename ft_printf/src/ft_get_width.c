/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 16:54:01 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/14 14:57:58 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_width(const char *str, t_id *id, int *pos)
{
	int		i;

	i = 0;
	while (str[i] == '*' || ft_isdigit((int)str[i]))
		i++;
	id->width = ft_substr(str, 0, i);
	*pos += i;
	return (i);
}
