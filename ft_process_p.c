/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_p.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:49:35 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/28 20:03:56 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*build_precision(t_format *fmt, char *c_arg, int ind)
{
	char	*n_arg;
	char	*aux;
	size_t	len;

	if (!(n_arg = (char*)ft_calloc(fmt->id->f_precision + 1 + ind,
					sizeof(char))))
		return (NULL);
	n_arg[0] = (c_arg[0] == '-' || c_arg[0] == '+') ? c_arg[0] : '0';
	ft_memset(&n_arg[ind], '0', fmt->id->f_precision - ft_strlen(c_arg) + ind);
	ft_memcpy(&n_arg[fmt->id->f_precision - ft_strlen(c_arg) + 2 * ind],
					&c_arg[ind], ft_strlen(c_arg));
	ft_free((void**)&c_arg);
	aux = ft_strdup("0x");
	len = 2;
	if (!ft_concat_str(&aux, n_arg, &len, ft_strlen(n_arg)))
		return (NULL);
	n_arg = aux;
	return (n_arg);
}

static char		*get_arg(t_format *fmt)
{
	void	*arg;
	size_t	ind;
	char	*aux;
	char	*c_arg;

	arg = va_arg(*(fmt->args), void*);
	if (fmt->id->precision && fmt->id->f_precision == 0 && arg == NULL) 
		return (ft_strdup("0x"));
	if (!fmt->id->precision && arg == NULL) 
		return (ft_strdup("0x0"));
	c_arg = ft_itoa_base_u((unsigned long int)arg, BS_HEX_LOW, 0);
	ind = 0;
	if (fmt->id->precision && (fmt->id->f_precision > (ft_strlen(c_arg) - ind)))
		return (build_precision(fmt, c_arg, ind));
	aux = ft_strdup("0x");
	ind = 2;
	if (!ft_concat_str(&aux, c_arg, &ind, ft_strlen(c_arg)))
		return (NULL);
	c_arg = aux;
	return (c_arg);
}

static void		fill_zeroes(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			str[i] = '0';
		if (i && (str[i] == '+' || str[i] == '-'))
		{
			str[0] = str[i];
			str[i] = '0';
		}
		i++;
	}
}

int				ft_process_p(t_format *fmt)
{
	size_t	o_l;
	size_t	a_l;
	char	*new_o;
	char	*arg;

	arg = get_arg(fmt);
	a_l = ft_strlen(arg);
	o_l = fmt->id->width && (fmt->id->f_width > a_l) ? fmt->id->f_width : a_l;
	if (!(new_o = (char*)ft_calloc(o_l + 1, sizeof(char))))
		return (0);
	ft_memset(new_o, ' ', o_l);
	if (ft_has_flag(fmt->id, FLG_MINUS))
		ft_memcpy(new_o, arg, ft_strlen(arg));
	else
		ft_memcpy(&new_o[o_l - a_l], arg, a_l);
	if (ft_has_flag(fmt->id, FLG_ZERO) && !fmt->id->precision)
		fill_zeroes(new_o);
	ft_free((void**)&arg);
	if (!ft_concat_str(&(fmt->output), new_o, &(fmt->out_len), o_l))
		return (0);
	return (42);
}
