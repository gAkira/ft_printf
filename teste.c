/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/27 10:48:38 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*fmt	=	"Esse eh % % a string %s yeah\t";
	char	*arg	=	"lalala";

	printf("%d\n", ft_printf(fmt, arg));
	printf("%d\n", printf(fmt,arg));
}
