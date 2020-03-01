/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:23:17 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/29 22:21:29 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_build_output(t_format *fmt, int *it)
{
	if (fmt->input[*it] != '\0')
	{
		if (fmt->input[*it] != '%')
		{
			if (!ft_concat_char(&(fmt->output), fmt->input[*it], fmt->out_len))
				return (0);
			(*it)++;
			(fmt->out_len)++;
		}
		else
		{
			fmt->id = ft_new_id(&(fmt->input[*it]));
			if (fmt->id != NULL)
			{
				if (ft_filter_id(fmt) && ft_process_arg(fmt))
					(*it) += fmt->id->length;
				else
					return (0);
			}
			else
				(*it) += fmt->input[*it + 1] == '\0' ? 1 : 2;
		}
		return (ft_build_output(fmt, it));
	}
	return (42);
}
