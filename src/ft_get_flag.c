/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:41:52 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 16:35:58 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_flag(const char *str, t_id *id, int *pos)
{
	int		f_cnt;

	f_cnt = 0;
	while (ft_is_present(str[f_cnt], ID_FLAGS))
	{
		if (str[f_cnt] == '-')
			id->flags |= FLG_MINUS;
		else if (str[f_cnt] == '0')
			id->flags |= FLG_ZERO;
		f_cnt++;
	}
	*pos += f_cnt;
	return (f_cnt);
}
