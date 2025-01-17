/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:40:59 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/01 13:10:32 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_concat_str(char **s1, char **s2, size_t *s1_len, size_t s2_len)
{
	size_t		i;

	i = 0;
	while (i < s2_len)
	{
		if (!ft_concat_char(s1, (*s2)[i], *s1_len))
			return (ft_free((void**)s2));
		(*s1_len)++;
		i++;
	}
	ft_free((void**)s2);
	return (42);
}
