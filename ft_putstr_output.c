/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:43:50 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/01 05:56:05 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_output(t_format *fmt, char *str)
{
	char	*new_out;

	new_out = ft_strjoin(fmt->output, str);
	if (new_out != NULL)
	{
		free(fmt->output);
		free(src);
		fmt->output = new_out;
		return (42);
	}
	return (0);
}
