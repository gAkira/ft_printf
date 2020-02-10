/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:56:22 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/09 22:20:49 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_concat_char(char **str, char c, size_t str_len)
{
	char	*aux;
	char	*new_str;

	aux = *str;
	new_str = (char*)ft_calloc(str_len + 2, sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_memmove(new_str, aux, str_len);
	new_str[str_len] = c;
	*str = new_str;
	free(aux);
	return (42);
}
