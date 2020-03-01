/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:35 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/29 22:48:34 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*build_precision(t_format *fmt, char *c_arg, int ind)
{
	char	*n_arg;

	if (!(n_arg = (char*)ft_calloc(fmt->id->f_precision + 1 + ind,
					sizeof(char))))
	{
		ft_free((void**)&c_arg);
		return (NULL);
	}
	n_arg[0] = (c_arg[0] == '-' || c_arg[0] == '+') ? c_arg[0] : '0';
	ft_memset(&n_arg[ind], '0', fmt->id->f_precision - ft_strlen(c_arg) + ind);
	ft_memmove(&n_arg[fmt->id->f_precision - ft_strlen(c_arg) + 2 * ind],
					&c_arg[ind], ft_strlen(c_arg));
	ft_free((void**)&c_arg);
	return (n_arg);
}

static char		*get_arg(t_format *fmt)
{
	int		arg;
	int		ind;
	char	*c_arg;

	arg = va_arg(*(fmt->args), int);
	if (fmt->id->precision && fmt->id->f_precision == 0 && arg == 0) 
		return (ft_strdup(""));
	if (ft_has_flag(fmt->id, FLG_PLUS))
		c_arg = ft_itoa_base_s(arg, BS_DEC, 1);
	else
		c_arg = ft_itoa_base(arg, BS_DEC);
	ind = (ft_has_flag(fmt->id, FLG_PLUS) || arg < 0 ? 1 : 0);
	if (fmt->id->precision && (fmt->id->f_precision > (ft_strlen(c_arg) - ind))
			&& !fmt->id->neg_2star)
	c_arg = build_precision(fmt, c_arg, ind);
	return (c_arg);
}

static int		def_if_fill(t_format *fmt)
{
	if (fmt->id->width)
	{
		if (fmt->id->precision)
			return (!fmt->id->neg_1star && fmt->id->neg_2star);
		else
			return (!ft_has_flag(fmt->id, FLG_MINUS));
	}
	else
	{
		if (fmt->id->precision)
			return (fmt->id->neg_2star);
		else
			return (0);
	}
}

static void		fill_zeroes(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			str[i] = '0';
		if (i != 0 && (str[i] == '+' || str[i] == '-'))
		{
			str[0] = str[i];
			str[i] = '0';
		}
		i++;
	}
}

int				ft_process_d(t_format *fmt)
{
	size_t	o_len;
	size_t	a_len;
	char	*new_o;
	char	*arg;

	arg = get_arg(fmt);
	a_len = ft_strlen(arg);
	o_len = a_len;
	if (fmt->id->width)
		o_len = fmt->id->f_width > o_len ? fmt->id->f_width : a_len;
	if (!(new_o = (char*)ft_calloc(o_len + 1, sizeof(char))))
	{
		ft_free((void**)&arg);
		return (0);
	}
	ft_memset(new_o, ' ', o_len);
	if (ft_has_flag(fmt->id, FLG_MINUS))
		ft_memcpy(new_o, arg, ft_strlen(arg));
	else
		ft_memcpy(&new_o[o_len - a_len], arg, a_len);
	if (ft_has_flag(fmt->id, FLG_ZERO) && def_if_fill(fmt))
		fill_zeroes(new_o);
	ft_free((void**)&arg);
	if (!ft_concat_str(&(fmt->output), &new_o, &(fmt->out_len), o_len))
		return (0);
	return (42);
}
