/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_output.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 05:23:17 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 18:30:43 by galves-d         ###   ########.fr       */
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
			if (fmt->id == NULL || !ft_filter_id(fmt))
				return (0);
			ft_process_arg(fmt);
			(*it) += fmt->id->length;
		}
		return (ft_build_output(fmt, it));
	}
	return (42);
}
