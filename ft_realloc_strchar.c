/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_strchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:56:22 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/04 02:01:57 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_realloc_strchar(char **str, char c)
{
	char	*aux;
	char	*new_str;
	int		str_len;

	aux = *str;
	str_len = ft_strlen(aux);
	new_str = (char*)ft_calloc(str_len + 2, sizeof(char));
	if (new_str == NULL)
		return (0);
	ft_strlcpy(new_str, aux, str_len + 1);
	new_str[str_len] = c;
	*str = new_str;
	free(aux);
	return (42);
}
