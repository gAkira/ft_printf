/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filter_id.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 18:51:41 by galves-d          #+#    #+#             */
/*   Updated: 2020/03/02 21:30:03 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	to_pos(t_format *fmt, int num, int star)
{
	if (num < 0)
	{
		if (star == 1)
		{
			fmt->id->flags |= FLG_MINUS;
			fmt->id->neg_1star = 1;
		}
		else
			fmt->id->neg_2star = 1;
	}
	return ((size_t)(num < 0 ? -num : num));
}

static int		filter_width(t_format *fmt)
{
	int		i;
	int		start;
	char	*num;

	i = 0;
	while (fmt->id->width && fmt->id->width[i] != '\0')
	{
		if (fmt->id->width[i] == '*')
		{
			fmt->id->f_width = to_pos(fmt, va_arg(*(fmt->args), int), 1);
			i++;
		}
		else
		{
			start = i;
			while (ft_isdigit((int)fmt->id->width[i]))
				i++;
			if (!(num = ft_substr(fmt->id->width, start, i - start)))
				return (0);
			fmt->id->f_width = (size_t)ft_atoi(num);
			ft_free((void**)&num);
		}
	}
	return (42);
}

static int		filter_precision(t_format *fmt)
{
	int		i;
	int		start;
	char	*num;

	i = 0;
	while (fmt->id->precision && fmt->id->precision[i] != '\0')
	{
		if (fmt->id->precision[i] == '*')
		{
			fmt->id->f_precision = to_pos(fmt, va_arg(*(fmt->args), int), 2);
			i++;
		}
		else
		{
			start = i;
			while (ft_isdigit((int)fmt->id->precision[i]))
				i++;
			if (!(num = ft_substr(fmt->id->precision, start, i - start)))
				return (0);
			fmt->id->f_precision = (size_t)ft_atoi(num);
			ft_free((void**)&num);
		}
	}
	return (42);
}

int				ft_filter_id(t_format *fmt)
{
	return (filter_width(fmt) && filter_precision(fmt));
}
