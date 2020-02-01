/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_output.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:56:22 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/01 06:03:28 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar_output(t_format *fmt, char c)
{
	char	*new_out;
	char	*str;

	str = (char*)ft_calloc(2, sizeof(char));
	if (str == NULL)
		return (0);
	str[0] = c;
	return (ft_putstr_output(fmt, str));
}
