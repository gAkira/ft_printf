/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 22:21:52 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/27 11:23:14 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_process_arg(t_format *fmt)
{
	if (!ft_strncmp(fmt->id->type, "c", 1))
		return (ft_process_c(fmt));
	else if (!ft_strncmp(fmt->id->type, "s", 1))
		return (ft_process_s(fmt));
	/*
	else if (!ft_strncmp(fmt->id->type, "p", 1))
		return (ft_process_p(fmt));
	else if (!ft_strncmp(fmt->id->type, "d", 1))
		return (ft_process_d(fmt));
	else if (!ft_strncmp(fmt->id->type, "i", 1))
		return (ft_process_i(fmt));
	else if (!ft_strncmp(fmt->id->type, "u", 1))
		return (ft_process_u(fmt));
	else if (!ft_strncmp(fmt->id->type, "x", 1))
		return (ft_process_x(fmt));
	else if (!ft_strncmp(fmt->id->type, "X", 1))
		return (ft_process_X(fmt));
		*/
	else if (!ft_strncmp(fmt->id->type, "%", 1))
		return (ft_process_pc(fmt));
	return (0);
}
