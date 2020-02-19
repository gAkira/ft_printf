/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teste.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galves-d <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:04:54 by galves-d          #+#    #+#             */
/*   Updated: 2020/02/19 19:16:16 by galves-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		main(void)
{
	char	*fmt	=	"Esse eh o %c char% yeah\t";
	char	c		=	'd';

	printf("%d\n", ft_printf(fmt, c));
	printf("%d\n", printf(fmt, c));
}
