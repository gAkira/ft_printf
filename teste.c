/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 18:41:14 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*fmt	=	"Esse eh o char %-3.5c yeah \t";
	char	c		=	'j';

	printf("%d\n", ft_printf(fmt, c));
	printf("%d\n", printf(fmt, c));
}
